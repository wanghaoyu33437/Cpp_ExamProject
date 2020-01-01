//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************
#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <dsound.h>
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dsound.lib")
 
class AudioDX; //����Ҫ�����ã�����������������

//������������������������������������������������������������������������
// wave��ʽ�Ķ�ȡ��
//������������������������������������������������������������������������
class AudioWave {
public:
	AudioWave();
	virtual ~AudioWave();
	//�򿪲���ȡWAVE�ļ�
	bool Open(const wchar_t *path);
	//��ȡ����ѯ�Ƿ����data����
	bool StartRead();
	//��ȡָ������
	bool Read(unsigned long size, void *data, unsigned long *nread);
	//�ͷ�ռ�õ���Դ
	bool Close();
	//��ȡwave��ʽ����
	WAVEFORMATEX *GetFormat() { return wfex; }
	//��ȡ�����С
	DWORD CkSize() const { return ckIn.cksize; }

protected:
	WAVEFORMATEX *wfex; //wave��ʽ�ṹ��ָ��
	HMMIO hmmio;		//�ļ����	
	MMCKINFO ckIn;		//MMCKINFO���󣨲�ѯ���ӿ飩
	MMCKINFO ckInRIFF;	//MMCKINFO���󣨸��飬���ļ���ȡ��
} ;


//������������������������������������������������������������������������
// AudioDXBuffer��
//������������������������������������������������������������������������
class AudioDXBuffer 
{
protected:
	LPDIRECTSOUNDBUFFER SndBuf;		// �������ӿ�ָ��
	LONG Volume;					// ����
	LONG Pan;						// ���������������
	DWORD Freq;						// Ƶ��

public:
	AudioDXBuffer();
	~AudioDXBuffer();
	// ������������������ƻ�������
	bool CreateBuffer(AudioDX &ds, WAVEFORMATEX *format, int size);
	// �������������������������趨ΪWAVE��ʽ
	bool CreateMainBuffer(AudioDX &ds, int freq=22050);
	// ����WAVE�ļ�,�����ļ�����д�뻺����
	bool LoadWave(AudioDX &ds, const wchar_t *path);
	// �ͷ�������Դ
	HRESULT Release();
	// �ָ�������
	HRESULT Restore();
	// ��ֹ����(�ָ���������ֹͣ��������)
	void Terminate();
	// ��������(���������Ƿ�ѭ��)
	bool Play(bool loop=false)
	{
		if(SndBuf == NULL) return false;
		if (FAILED(SndBuf->Play(0, 0, loop? DSBPLAY_LOOPING: 0)))
			return false;
		return true;
	}
	// ֹͣ��������
	bool Stop(){ return SndBuf->Stop() == DS_OK; }
	// �жϻ������Ƿ��ڻ�Ծ״̬
	bool IsAlive() const { return SndBuf != 0; }
	// ����"->"������, ��ʾSndBuf����
	LPDIRECTSOUNDBUFFER operator ->() { return SndBuf; }
	
} ;


//������������������������������������������������������������������������
// AudioDX��
//������������������������������������������������������������������������
class AudioDX 
{
public:
	AudioDX();
	~AudioDX();
	// ����DirectSound�������ú������𲢴�����������
	bool CreateDS(HWND hWnd, int freq=22050);
	// �ͷ�DirectSound����DirectSound����������
	void ReleaseAll();
	// ʧȥ�������ڴ�ʱ��ԭ
	HRESULT RestoreAll();
	// ����"->"������, ��ʾds����
	LPDIRECTSOUND operator ->() { return ds; }

protected:
	LPDIRECTSOUND ds;		// DirectSound����
	AudioDXBuffer dsbuf;	// DirectSound�������
} ;
