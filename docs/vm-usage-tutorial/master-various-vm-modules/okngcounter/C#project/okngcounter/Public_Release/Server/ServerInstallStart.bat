@rem ע�ͣ��л�����ǰ·��
cd /d %~dp0
@rem ע�ͣ��������ļ�����ȡ��������
set ServiceName=VisionMasterServer
for /f "tokens=1,2* delims== " %%a in (ServerConfiguration.ini) do (
@ if "%%a"=="ServiceName" (set ServiceName=%%b 
@ goto end )
 )

:end
@rem ע�ͣ�ж�ط���
@net stop %ServiceName%
@sc delete %ServiceName%

@rem ע�ͣ���װ����
start /b /wait VisionMasterServer.exe -i
@net start %ServiceName%
