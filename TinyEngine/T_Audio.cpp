//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************
#include "T_Audio.h"



//������������������������������������������������������������������������
// ����ΪAudioWave��Ա�����Ķ���
//������������������������������������������������������������������������                                                                   

AudioWave::AudioWave():hmmio(0), wfex(0)
{	}

AudioWave::~AudioWave()
{
	Close();
}

//��ָ��·���µ�WAVE�ļ�
bool AudioWave::Open(const wchar_t *path)
{
	//��ָ��·���µ�WAVE�ļ����������ļ����
	hmmio =  mmioOpenW((wchar_t *)path, NULL, MMIO_ALLOCBUF | MMIO_READ);
	if(hmmio == NULL)	return false;

	// ���ļ������ƶ���RIFF����
	if(mmioDescend(hmmio, &ckInRIFF, NULL, 0) != 0)
		return false;

	//�ж��ļ������Ƿ�Ϊ�Ƿ�ΪWAVE����
	if((ckInRIFF.ckid != FOURCC_RIFF)||
		(ckInRIFF.fccType != mmioFOURCC('W', 'A', 'V', 'E')))
		return false;

	//�����ļ����ݵ�fmt����
	ckIn.ckid = mmioFOURCC('f', 'm', 't', ' ');
	if(mmioDescend(hmmio, &ckIn, &ckInRIFF, MMIO_FINDCHUNK) != 0)
		return false;

	//���fmt����С��PCMWAVEFORMAT����ʾfmt����̫С
	if(ckIn.cksize < sizeof(PCMWAVEFORMAT)) return false;

	wfex = (WAVEFORMATEX *)new char[ckIn.cksize];
	if(wfex == 0)  return false;

	//��fmt�������wfex�ṹ��
	if(mmioRead(hmmio, (HPSTR)wfex, ckIn.cksize) != (LONG)ckIn.cksize)
		return false;

	//������ϣ�����fmt����
	if(mmioAscend(hmmio, &ckIn, 0) != 0) return false;

	return true;
}

//��ȡ����ѯ�Ƿ����data����
bool AudioWave::StartRead()
{
	if(mmioSeek(hmmio, ckInRIFF.dwDataOffset + sizeof(FOURCC), SEEK_SET) == -1)
		return false;

	//�����ļ����ݵ�data����
	ckIn.ckid = mmioFOURCC('d', 'a', 't', 'a');
	//���û��data����
	if(mmioDescend(hmmio, &ckIn, &ckInRIFF, MMIO_FINDCHUNK) != 0)
		return false;			
	return true;
}

//��ȡָ������
bool AudioWave::Read(unsigned long size, void *data, unsigned long *nread)
{
	*nread = 0;
	int result = mmioRead(hmmio, (HPSTR)data, size);
	if (result == -1) return false;
	*nread = (unsigned)result;
	return true;
}

//�ر��ļ�
bool AudioWave::Close()
{
	delete[] (char *)wfex;
	wfex = 0;

	if(hmmio != NULL) 
		return mmioClose(hmmio, 0) == 0;

	return true;
}


//������������������������������������������������������������������������
// ����ΪAudioDXBuffer���Ա�����Ķ���
//������������������������������������������������������������������������                                                                    

//���캯��
AudioDXBuffer::AudioDXBuffer():SndBuf(NULL),Volume(0),Pan(0),Freq(0)
{	}

//��������
AudioDXBuffer::~AudioDXBuffer()
{
	if(SndBuf) SndBuf->Release();
}

//������������������ƻ�������
bool AudioDXBuffer::CreateBuffer(AudioDX &ds, WAVEFORMATEX *format, int size)
{
	DSBUFFERDESC dsbd;
	//ʹ��0���dsbd�ڴ��
	ZeroMemory(&dsbd, sizeof(dsbd));

	//����dsbd����ֵ
	dsbd.dwSize = sizeof(dsbd);
	dsbd.dwFlags =	DSBCAPS_GETCURRENTPOSITION2| 
		DSBCAPS_GLOBALFOCUS| 
		DSBCAPS_CTRLPOSITIONNOTIFY| 
		DSBCAPS_CTRLVOLUME| 
		DSBCAPS_CTRLPAN| 
		DSBCAPS_CTRLFREQUENCY;
	dsbd.dwBufferBytes = size;
	dsbd.lpwfxFormat = format;

	//����������
	HRESULT result = ds->CreateSoundBuffer(&dsbd, &SndBuf, NULL);
	if (FAILED(result)) return false;

	//��ȡ����������ֵ��ʹ�û�ȡ��ֵ��ʼ����ر���
	SndBuf->GetVolume(&Volume);
	SndBuf->GetPan(&Pan);
	SndBuf->GetFrequency(&Freq);

	return true;
}

//�������������������������趨ΪWAVE��ʽ
bool AudioDXBuffer::CreateMainBuffer(AudioDX &ds, int freq)
{
	DSBUFFERDESC dsbd;
	//ʹ��0���dsbd�ڴ��
	ZeroMemory(&dsbd, sizeof(dsbd));

	//����dsbd����ֵ
	dsbd.dwSize = sizeof(dsbd); 
	dsbd.dwFlags = DSBCAPS_CTRLVOLUME | 
		DSBCAPS_CTRLPAN | 
		DSBCAPS_PRIMARYBUFFER;//�ñ�־��ʾҪ������������
	dsbd.dwBufferBytes = 0;
	dsbd.lpwfxFormat = NULL;

	//����DirectSound���󴴽���������
	HRESULT result = ds->CreateSoundBuffer(&dsbd, &SndBuf, NULL);
	if(FAILED(result)) return false;

	WAVEFORMATEX wfex;
	//ʹ��0���wfex�ڴ��
	ZeroMemory(&wfex, sizeof(wfex));

	//�趨WAVE��ʽ��������
	wfex.wFormatTag = WAVE_FORMAT_PCM;
	wfex.nChannels = 2;
	wfex.nSamplesPerSec = freq;
	wfex.nBlockAlign = 4;
	wfex.nAvgBytesPerSec = wfex.nSamplesPerSec * wfex.nBlockAlign;
	wfex.wBitsPerSample = 16;

	//����������ʽ����ΪWAVE�ļ���ʽ
	result = SndBuf->SetFormat(&wfex);
	if(FAILED(result)) return false;

	//��ȡ����������ֵ��ʹ�û�ȡ��ֵ������ر���
	SndBuf->GetVolume(&Volume);
	SndBuf->GetPan(&Pan);
	SndBuf->GetFrequency(&Freq);

	return true;
}

//����WAVE�ļ�,�����ļ�����д�뻺����
bool AudioDXBuffer::LoadWave(AudioDX &ds, const wchar_t *path)
{
	AudioWave file;
	if(!file.Open(path) || !file.StartRead()) return false;

	Release();		// ����Ѿ��л����������ͷ�

	//ʹ��WAVE�ļ���С����������
	if(!CreateBuffer(ds, file.GetFormat(), file.CkSize()))
		return false;

	//��WAVE�ļ�����д�뻺����
	void *ptr1, *ptr2;
	DWORD bytes1, bytes2;
	HRESULT result = SndBuf->Lock( 0, file.CkSize(), 
		&ptr1, &bytes1, 
		&ptr2, &bytes2, 0);
	//�����������ʧ����ָ���Ȼ��������д������
	if(result == DSERR_BUFFERLOST) {
		Restore();
		result = SndBuf->Lock( 0, file.CkSize(), 
			&ptr1, &bytes1, 
			&ptr2, &bytes2, 0);
	}

	//д��ɹ��󣬽������
	if(SUCCEEDED(result)) {
		bool readerror = false;
		DWORD nread;

		//�ж��Ƿ���ڴ���
		if(!file.Read(bytes1, (LPBYTE)ptr1, &nread) || 
			bytes1 != nread)
			readerror = true;
		if(bytes2) 
		{
			if(!file.Read(bytes2, (LPBYTE)ptr2, &nread) || 
				bytes2 != nread)
				readerror = true;
		}

		//�������
		result = SndBuf->Unlock(ptr1, bytes1, ptr2, bytes2);

		if(readerror) return false;

		return true;
	}

	return false;
}

//�ͷ�������Դ
HRESULT AudioDXBuffer::Release()
{
	HRESULT result = DS_OK;
	if(SndBuf) result = SndBuf->Release();
	SndBuf = 0;
	return result;
}

//�ָ�������
HRESULT AudioDXBuffer::Restore()
{
	HRESULT result = DS_OK;
	if(SndBuf) return SndBuf->Restore();
	return DS_OK;
}

void AudioDXBuffer::Terminate()
{
 	if(SndBuf)
	{
		if(FAILED(SndBuf->Restore())) return;		
		if(FAILED(SndBuf->Stop())) return;
	}
}

//������������������������������������������������������������������������ 
// ����ΪAudioDX���Ա�����Ķ���
//������������������������������������������������������������������������                                                                    

//���캯��
AudioDX::AudioDX()
{
	ds = 0;
}

//��������
AudioDX::~AudioDX()
{
	ReleaseAll();
}

//����DirectSound�������ú������𲢴�����������
bool AudioDX::CreateDS(HWND hWnd, int freq)
{
	//����DirectSound����
	HRESULT result = DirectSoundCreate(NULL, &ds, NULL);
	if (FAILED(result)) return false;

	//����DirectSound�����������ȼ���
	result = ds->SetCooperativeLevel(hWnd, DSSCL_PRIORITY);
	if (FAILED(result))	return false;

	//����DirectSound������
	return dsbuf.CreateMainBuffer(*this, freq);
}

//�ͷ�DirectSound����DirectSound����������
void AudioDX::ReleaseAll()
{
	if (ds) {
		dsbuf.Release();
		ds->Release();
		ds = 0;
	}
}

//ʧȥ�������ڴ�ʱ��ԭ
HRESULT AudioDX::RestoreAll()
{
	HRESULT result = dsbuf.Restore();
	if (result != DS_OK) return result;

	return DS_OK;
}