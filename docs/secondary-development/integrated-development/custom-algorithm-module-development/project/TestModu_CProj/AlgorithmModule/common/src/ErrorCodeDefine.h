/***************************************************************************************************
 *
 * ��Ȩ��Ϣ����Ȩ���� (c) 2020, ��������Ȩ��
 *
 * �ļ����ƣ�ErrorCodeDefine.h
 * ժ    Ҫ��������ͷ�ļ�
 *
 * ��    �ߣ��Ӿ�ƽ̨��
 * ��    �ڣ�2020-01-17 11:09:05
 * ��    ע���½�

 * Copyright information: All Right Reserved.
 *
 * File name: ErrorCodeDefine.h
 * Brief: Error code definition
 *
 * Author: VisionMaster Team
 * Date: 2020-01-17 11:09:05
 * Note: New
 ****************************************************************************************************/

#ifndef _IMVS_6000_ERROR_CODE_DEFINE_H_
#define _IMVS_6000_ERROR_CODE_DEFINE_H_

// CH: ������ | EN: Error code
#define   IMVS_EC_OK                                        0x00000000  // CH: �޴��� | EN: No error

/****************************************************************************
 * ͨ�ô��� 0xE0000000~0xE00000FF
 * Universal errors 0xE0000000~0xE00000FF
 ****************************************************************************/
#define   IMVS_EC_VERSION                                   0xE0000000  // CH: �汾���� | EN: Incorrect version No.
#define   IMVS_EC_PARAM                                     0xE0000001  // CH: �������� | EN: Incorrect parameter
#define   IMVS_EC_RESOURCE_CREATE                           0xE0000002  // CH: ��Դ����ʧ�� | EN: Applying for resource failed
#define   IMVS_EC_OUTOFMEMORY                               0xE0000003  // CH: �ڴ治�� | EN: Insufficient memory
#define   IMVS_EC_POINTER_CAST                              0xE0000004  // CH: ָ��ת������ | EN: Pointer conversion failed
#define   IMVS_EC_MEMORY_BEYOND_THRESHOLD                   0xE0000005  // CH: ϵͳ�ڴ�ʹ���ʳ�����ֵ | EN: The CPU usage is too high
#define   IMVS_EC_INVALID_HANDLE                            0xE0000006  // CH: �����Ч | EN: Invalid or incorrect handle
#define   IMVS_EC_NOT_SUPPORT                               0xE0000007  // CH: ������֧�� | EN: This operation is not supported
#define   IMVS_EC_NOT_READY                                 0xE0000008  // CH: ��Դδ��ʼ����δ׼���� | EN: Initializing resource failed
#define   IMVS_EC_WAIT_TIMEOUT                              0xE0000009  // CH: �ȴ���ʱ | EN: Waiting timed out
#define   IMVS_EC_NULL_PTR                                  0xE000000A  // CH: ָ��Ϊ�� | EN: Null pointer
#define   IMVS_EC_PROCESS_START_FAIL                        0xE000000B  // CH: ��������ʧ�� | EN: Starting up process failed
#define   IMVS_EC_PROCESS_ALREADY_START                     0xE000000C  // CH: �ͻ��˳��������� | EN: The client is already started up
#define   IMVS_EC_SOLUTION_LOADING                          0xE000000D  // CH: ���ڼ��ط��� | EN: Solution is loading
#define   IMVS_EC_SOLUTION_SAVING                           0xE000000E  // CH: ���ڱ��淽�� | EN: Solution is saving
#define   IMVS_EC_CALL_ORDER                                0xE000000F  // CH: �ӿڵ���˳����� | EN: Incorrect API call sequence
#define   IMVS_EC_LOAD_LIBRARY                              0xE0000010  // CH: ��̬�����ʧ�� | EN: Loading dynamic library failed
#define   IMVS_EC_GET_FUN_ADDRESS                           0xE0000011  // CH: ��ȡ������ַʧ�� | EN: Getting function address failed
#define   IMVS_EC_PARAM_BUF_LEN                             0xE0000012  // CH: �������������Ȳ��� | EN: Insufficient buffer size
#define   IMVS_EC_GETTING_PLAT_INFO                         0xE0000013  // CH: ���ڻ�ȡ�ײ���Ϣ | EN: Getting underlying information
#define   IMVS_EC_INDEX_OUT_OF_BOUNDARY                     0xE0000014  // CH: ����ֵԽ�� | EN: The index No. is out of limit
#define   IMVS_EC_OPEN_FILEMAPPING                          0xE0000015  // CH: �򿪹����ڴ�ʧ�� | EN: Opening sharing memory failed
#define   IMVS_EC_THREAD_START_FAIL                         0xE0000016  // CH: �����߳�ʧ�� | EN: Starting thread failed
#define   IMVS_EC_PROTOCOL                                  0xE0000017  // CH: Э��������� | EN: Parsing protocol failed
#define   IMVS_EC_DATA_ERROR                                0xE0000018  // CH: ���ݴ��� | EN: Incorrect data
#define   IMVS_EC_NOT_IMPLEMENTED                           0xE0000019  // CH: ����δʵ�� | EN: No operation is done
#define   IMVS_EC_DATA_OVER_SIZE                            0xE000001A  // CH: ���ݴ�С�������� | EN: No more data is allowed
#define   IMVS_EC_PRECONDITION                              0xE000001B  // CH: ǰ���������� | EN: Pre-condition is wrong
#define   IMVS_EC_RUNTIME                                   0xE000001C  // CH: ���л������� | EN: Running environment error
#define   IMVS_EC_SOLUTION_CLOSING                          0xE000001D  // CH: ���ڹرշ��� | EN: Closing solution
#define   IMVS_EC_SILENT_EXEC_STATUS                        0xE000001E  // CH: ��Ĭִ����   | EN: In silent execution
#define   IMVS_EC_DYNAMICIO_PARAM_NOT_FOUND                 0xE000001F  // CH: ��̬IO�����޷��ҵ�   | EN: No dynamicIO param found
#define   IMVS_EC_CLOSE_FILEMAPPING                         0xE0000020  // CH: �رչ����ڴ�ʧ�� | EN: Close sharing memory failed
#define   IMVS_EC_UNKNOWN                                   0xE00000FF  // CH: δ֪���� | EN: Unknown error


/****************************************************************************
 * ͨ����ش��� 0xE0000100~0xE00001FF
 * Communication-related errors 0xE0000100~0xE00001FF
 ****************************************************************************/
#define   IMVS_EC_COMMU_SOCKET_CREAT                        0xE0000100  // CH: socket����ʧ�� | EN: Creating socket failed
#define   IMVS_EC_COMMU_SOCKET_INVALID                      0xE0000101  // CH: socket��Ч | EN: Invalid socket
#define   IMVS_EC_COMMU_SERIAL_OPEN                         0xE0000102  // CH: �򿪴���ʧ�� | EN: Connecting to serial port failed
#define   IMVS_EC_COMMU_INVALID_ADDRESS                     0xE0000103  // CH: ��ַ��Ч | EN: Invalid address
#define   IMVS_EC_COMMU_ADDRESS_INUSE                       0xE0000104  // CH: ��ַ�ѱ�ʹ�� | EN: Unavailable address
#define   IMVS_EC_COMMU_CONNECT                             0xE0000105  // CH: ����ʧ�� | EN: Connection failed
#define   IMVS_EC_COMMU_DISCONNECT                          0xE0000106  // CH: �Ͽ�����ʧ�� | EN: Disconnection failed
#define   IMVS_EC_COMMU_SEND_FAIL                           0xE0000107  // CH: ����ʧ�� | EN: Sending data failed
#define   IMVS_EC_COMMU_RECV_TIMEOUT                        0xE0000108  // CH: ���ճ�ʱ | EN: Response timed out
#define   IMVS_EC_COMMU_MESSAGE_FORMAT                      0xE0000109  // CH: ��Ϣ��ʽ���� | EN: Incorrect protocol format
#define   IMVS_EC_COMMU_MSG_TOO_LONG                        0xE000010A  // CH: ���ĳ��ȳ������� | EN: Maximum message length reached
#define   IMVS_EC_COMMU_HEARTBEAT                           0xE000010B  // CH: �����쳣 | EN: Heartbeat exception


/****************************************************************************
 * �ļ���ش��� 0xE0000200~0xE00002FF
 * File-related errors 0xE0000200~0xE00002FF
 ****************************************************************************/
#define   IMVS_EC_FILE_MKDIR                                0xE0000200  // CH: ����·������ | EN: Incorrect file path
#define   IMVS_EC_FILE_OPEN                                 0xE0000201  // CH: �ļ��޷��� | EN: Opening file failed
#define   IMVS_EC_FILE_SAVE                                 0xE0000202  // CH: �����ļ�����ʧ�� | EN: Saving file failed
#define   IMVS_EC_FILE_NOT_FOUND                            0xE0000203  // CH: �ļ������� | EN: The file does not exist
#define   IMVS_EC_FILE_FORMAT                               0xE0000204  // CH: �ļ���ʽ���� | EN: Incorrect file format
#define   IMVS_EC_FILE_COMPRESS                             0xE0000205  // CH: �ļ�ѹ��ʧ�� | EN: Compressing file failed
#define   IMVS_EC_FILE_DECOMPRESS                           0xE0000206  // CH: �ļ���ѹʧ�� | EN: Decompressing file failed
#define   IMVS_EC_FILE_XML_ELEMENT                          0xE0000207  // CH: xml��element������ | EN: The "element" does not exist in the XML file
#define   IMVS_EC_FILE_XML_ATTRIBUTE                        0xE0000208  // CH: xml��Attribute������ | EN: The "attribute" does not exist in the XML file
#define   IMVS_EC_FILE_PATH_TOO_LONG                        0xE0000209  // CH: �ļ�·�����ȳ���ϵͳ���ֵ | EN: The file path is too long
#define   IMVS_EC_FILE_BE_OCCUPIED                          0xE000020A  // CH: �ļ���ռ�� | EN: The file is already occupied
#define   IMVS_EC_FILE_PATH_EMPTY                           0xE000020B  // CH: Ŀ��·��Ϊ�� | EN: The target path is empty
#define   IMVS_EC_FILE_INSUFFICIENT_DISK_SPACE              0xE000020C  // CH: ���̿ռ䲻�� | EN: Insufficient disk space
#define   IMVS_EC_FILE_UI_NOT_FOUND                         0xE000020D  // CH: �����ļ������� | EN: Interface file does not exist
#define   IMVS_EC_FILE_BACKUP                               0xE000020E  // CH: �ļ�����ʧ�� | EN: Backup file failed
#define   IMVS_EC_FILE_PATH_INVALID                         0xE000020F  // CH: Ŀ��·����Ч | EN: The target path is invalid


/****************************************************************************
 * ģ��������� 0xE0000300~0xE00003FF
 * Module operation errors 0xE0000300~0xE00003FF
 ****************************************************************************/
#define   IMVS_EC_MODULE_BUSY                               0xE0000300  // CH: ���̴���æµ״̬ | EN: The procedure is busy
#define   IMVS_EC_MODULE_COUNT_BEYOND                       0xE0000301  // CH: ģ������������� | EN: Maximum number of modules reached
#define   IMVS_EC_MODULE_NOT_FOUND                          0xE0000302  // CH: ģ�鲻���� | EN: The module does not exist
#define   IMVS_EC_MODULE_ALREADY_EXIST                      0xE0000303  // CH: ģ���Ѵ��� | EN: The module already exists
#define   IMVS_EC_MODULE_EMPTY                              0xE0000304  // CH: ģ������Ϊ0 | EN: No module
#define   IMVS_EC_MODULE_NOT_REGISTER                       0xE0000305  // CH: ģ��δע�� | EN: The module is not registered
#define   IMVS_EC_MODULE_SUBSCRIBE_FAIL                     0xE0000306  // CH: ģ�鶩��ʧ�� | EN: Subscribing module failed
#define   IMVS_EC_MODULE_PROC_CTRL_EXCEPT                   0xE0000307  // CH: ���̿���ģ������쳣�������� | EN: Procedure control module exception
#define   IMVS_EC_MODULE_INPUT_CFG_UNDONE                   0xE0000308  // CH: ģ������δ������� | EN: The module input parameter is not configured
#define   IMVS_EC_MODULE_INPUT_NOT_FOUND                    0xE0000309  // CH: ģ�������޷��ҵ� | EN: No module input found
#define   IMVS_EC_MODULE_INPUT_STATUS                       0xE000030A  // CH: ģ������״̬���� | EN: Module input status error
#define   IMVS_EC_MODULE_INPUT_COUNT                        0xE000030B  // CH: ģ������������� | EN: Incorrect number of module inputs
#define   IMVS_EC_MODULE_INPUT_BUF_LEN                      0xE000030C  // CH: ģ�����뻺��������̫С | EN: The buffer size of module input is too small
#define   IMVS_EC_MODULE_PARAM_NOT_SUPPORT                  0xE000030D  // CH: ������֧�� | EN: This parameter is not supported
#define   IMVS_EC_MODULE_PARAM_VALUE_ILLEGAL                0xE000030E  // CH: ����ֵ��Ч | EN: Invalid parameter value
#define   IMVS_EC_MODULE_PARAM_TYPE                         0xE000030F  // CH: �������ʹ��� | EN: Incorrect parameter type
#define   IMVS_EC_MODULE_IMPORT_DATA                        0xE0000310  // CH: �������ݸ�ʽ���� | EN: The imported data format is incorrect
#define   IMVS_EC_MODULE_CONTINUE_EXECUTE                   0xE0000311  // CH: ��������ִ�� | EN: Continuously executing
#define   IMVS_EC_MODULE_PROCEDURE_EMPTY                    0xE0000312  // CH: �����ڵ�ģ������Ϊ0 | EN: No module in the procedure
#define   IMVS_EC_MODULE_HEARTBEAT_EXCEPTION                0xE0000313  // CH: ģ�����������쳣 | EN: Module heartbeat exception
#define   IMVS_EC_MODULE_SUB_RST_NOT_FOUND                  0xE0000314  // CH: δ�ҵ����Ľ��ֵ | EN: No subscription result found
#define   IMVS_EC_MODULE_OUT_NOT_FOUND                      0xE0000315  // CH: ģ������޷��ҵ� | EN: No module output found
#define   IMVS_EC_MODULE_PROCEDURE_NOT_FOUND                0xE0000316  // CH: ���̲����� | EN: The procedure does not exist
#define   IMVS_EC_MODULE_PROCEDURE_ALREADY_EXIST            0xE0000317  // CH: �����Ѵ��� | EN: The procedure already exists
#define   IMVS_EC_MODULE_CREATE_ALG_MODULE_FAILED           0xE0000318  // CH: �����㷨ģ��ʧ�� | EN: Creating algorithm module failed
#define   IMVS_EC_MODULE_LOOP_ALREADY_EXIST                 0xE0000319  // CH: ѭ���Ѵ��� | EN: The loop already exists
#define   IMVS_EC_MODULE_LOOP_NOT_FOUND                     0xE000031A  // CH: ѭ�������� | EN: The loop does not exist
#define   IMVS_EC_MODULE_SUB_RECORD_NOT_FOUND               0xE000031B  // CH: δ�ҵ����ļ�¼ | EN: No subscription record found
#define   IMVS_EC_MODULE_SUB_PARAM_ERROR                    0xE000031C  // CH: ���Ĳ������� | EN: Incorrect subscription parameter
#define   IMVS_EC_MODULE_PROCEDURE_DISABLED                 0xE000031D  // CH: ���̴��ڽ���״̬ | EN: Process is disabled
#define   IMVS_EC_MODULE_TRIGGERSTRING_NOT_MATCH            0xE000031E  // CH: �����ַ���ƥ�� | EN: Trigger string mismatch
#define   IMVS_EC_MODULE_GLOBALSCRIPT_PROCESSING            0xE000031F  // CH: ȫ�ֽű���������ִ���� | EN: Global scripting process is executing
#define   IMVS_EC_MODULE_GLOBALSCRIPT_COMPILE_FAIL          0xE0000320  // CH: ȫ�ֽű�����ʧ�� | EN: Global script compilation failed
#define   IMVS_EC_MODULE_GROUP_ALREADY_EXIST                0xE0000321  // CH: �����Ѵ��� | EN: Group already exists
#define   IMVS_EC_MODULE_GROUP_NOT_FOUND                    0xE0000322  // CH: ���鲻���� | EN: Group does not exist
#define   IMVS_EC_MODULE_GROUP_EXPORTING                    0xE0000323  // CH: ���ڵ���Group | EN: Exporting group
#define   IMVS_EC_MODULE_GROUP_IMPORTING                    0xE0000324  // CH: ���ڵ���Group | EN: Importing group
#define   IMVS_EC_MODULE_BEYOND_NESTED_LAYER                0xE0000325  // CH: ����Ƕ�ײ㼶 | EN: Beyond module nested layer
#define   IMVS_EC_PROCESS_COUNT_BEYOND                      0xE0000326  // CH: ����������������  | EN: Maximum number of process reached
#define   IMVS_EC_MODULE_NAME_DUPLICATED                    0xE0000327  // CH: �����ظ�  | EN: Name duplicated
#define   IMVS_EC_PROCESS_IN_VMFILE_SOL                     0xE0000328  // CH: ���̰����ڷ����Ľ����ļ���  | EN: The procedure is contained within interface file of solution
#define   IMVS_EC_MODULE_PROCEDURE_EXPORTING                0xE0000329  // CH: ���ڵ������� | EN: Exporting procedure
#define   IMVS_EC_MODULE_PROCEDURE_IMPORTING                0xE000032A  // CH: ���ڵ������� | EN: Importing procedure
#define   IMVS_EC_MODULE_ROUGH_MATCH_FAIL                   0xE000032B  // CH: �ַ�ȱ�ݴֶ�λʧ�� | EN: Character defect coarse positioning failed
#define   IMVS_EC_MODULE_COARSE_OVER_SCORE                  0xE000032C  // CH: �ٶ���ֵ������Сƥ����� | EN: The speed threshold is greater than the minimum match score
#define   IMVS_EC_MODULE_SUB_CONNECTION_ERROR               0xE000032D  // CH: ��ģ����ڶ��Ĺ�ϵ�����߲��ɴ� | EN: Subscribe one module output but connection does not exist
#define   IMVS_EC_MODULE_SCALE_VALUE_OVERFLOW               0xE000032E  // CH: λ������XY�߶�ֵ������Χ(0~10000) | EN�� The value of scale X or Y is too big
#define   IMVS_EC_MODULE_EXACT_MATCH_FAIL                   0xE000032F  // CH: �ַ�ȱ�ݾ���λʧ�� | EN: Character defect fine positioning failed
#define   IMVS_EC_MODULE_EXACT_MATCH_CHANGED                0xE0000330  // CH: ����λ��Ϣ�ı� ���½���ͳ��ѵ�� | EN: Resume statistical training due to fine position change
#define   IMVS_EC_MODULE_PARAM_INPUT                        0xE0000331  // CH: ģ������IO����Ϊ0 | EN: No input
#define   IMVS_EC_MODULE_SUB_GLOBAL_VARIABLE                0xE0000332  // CH: ������ȫ�ֱ��� | EN: Subscribe global variable
#define   IMVS_EC_MODULE_HAS_LOAD_FAIL                      0xE0000333  // CH: ���ڼ���ʧ��ģ�� | EN: There are modules that failed to load
#define   IMVS_EC_MODULE_OVERRUN_IMAGECOUNT                 0xE0000334  // CH: ��һͼ��Դ��ͼ��������120 | EN�� The number of saved imaged of the imagesource is greater than 120 
#define   IMVS_EC_MODULE_INPECT_MATCH_FAIL                  0xE0000335  // ch: δƥ�䵽Ŀ���ƥ������쳣 | EN�� The target is not matched or the number of matches is abnormal
#define   IMVS_EC_MODULE_GROUP_OUTPUT_MODULE_FAILED         0xE0000336  // CH: group�������ģ��ִ��ʧ�� | EN:  


/****************************************************************************
 * ������� 0xE0000400~0xE00004FF
 * Camera errors 0xE0000400~0xE00004FF
 ****************************************************************************/
#define   IMVS_EC_CAMERA_RUNTIME                            0xE0000400  // CH: ���л��������� | EN: Running environment exception
#define   IMVS_EC_CAMERA_NOT_IMPLEMENTED                    0xE0000401  // CH: ������豸֧�� | EN: This command is not supported by the device
#define   IMVS_EC_CAMERA_ACCESS_DENIED                      0xE0000402  // CH: �豸�޷���Ȩ�� | EN: No permission for this device to access to
#define   IMVS_EC_CAMERA_BUSY                               0xE0000403  // CH: �豸æ��������Ͽ� | EN: Device is busy or network is disconnected
#define   IMVS_EC_CAMERA_PACKET                             0xE0000404  // CH: ��������ݴ��� | EN: Network data packet error
#define   IMVS_EC_CAMERA_USB_READ                           0xE0000405  // CH: ��USB���� | EN: Reading from USB failed
#define   IMVS_EC_CAMERA_USB_WRITE                          0xE0000406  // CH: дUSB���� | EN: Writing to USB failed
#define   IMVS_EC_CAMERA_USB_DEVICE                         0xE0000407  // CH: �豸�쳣 | EN: USB device exception
#define   IMVS_EC_CAMERA_USB_BANDWIDTH                      0xE0000408  // CH: USB������ | EN: Insufficient USB bandwidth
#define   IMVS_EC_CAMERA_NODATA                             0xE0000409  // CH: ��������� | EN: No data in the camera
#define   IMVS_EC_CAMERA_EMPTY                              0xE0000410  // CH: δ������� | EN: Camera not connected
#define   IMVS_EC_CAMERA_TYPE_NOT_MATCH                     0xE0000411  // CH: ������Ͳ�ƥ�� | EN: Camera type mismatch


/****************************************************************************
 * �㷨���� 0xE0000500~0xE00005FF
 * Algorithm errors 0xE0000500~0xE00005FF
 ****************************************************************************/
#define   IMVS_EC_ALGORITHM_IMG_DATA_NULL                   0xE0000500  // CH: ͼ�����ݴ洢��ַΪ�գ�ĳ�������� | EN: Image data storage path is empty (a component)
#define   IMVS_EC_ALGORITHM_IMG_STEP                        0xE0000501  // CH: ͼ������step������ƥ�� | EN: The image width/height and step parameter mismatches
#define   IMVS_EC_ALGORITHM_IMG_SIZE                        0xE0000502  // CH: ͼ���߲���ȷ���߳�����Χ | EN: The image width/height is incorrect or out of limit
#define   IMVS_EC_ALGORITHM_IMG_FORMAT                      0xE0000503  // CH: ͼ���ʽ����ȷ���߲�֧�� | EN: The image format is incorrect or not supported
#define   IMVS_EC_ALGORITHM_MEM_SIZE_ALIGN                  0xE0000504  // CH: �ڴ�ռ��С���������Ҫ�� | EN: The memory size does not meet with the alignment requirement
#define   IMVS_EC_ALGORITHM_MEM_LACK                        0xE0000505  // CH: �ڴ�ռ��С���� | EN: Insufficient memory size
#define   IMVS_EC_ALGORITHM_MEM_ALIGN                       0xE0000506  // CH: �ڴ���벻����Ҫ�� | EN: The memory alignment does not meet with the requirement
#define   IMVS_EC_ALGORITHM_ABILITY_ARG                     0xE0000507  // CH: ABILITY������Ч��Ա���� | EN: Invalid variable member exists in the ABILITY
#define   IMVS_EC_ALGORITHM_CPUID                           0xE0000508  // CH: cpu��֧���Ż������е�ָ� | EN: Optimizing command set of code is not supported by CPU
#define   IMVS_EC_ALGORITHM_DATA_SIZE                       0xE0000509  // CH: ���ݴ�С����ȷ | EN: Incorrect data size
#define   IMVS_EC_ALGORITHM_CALL_BACK                       0xE000050A  // CH: �ص��������� | EN: Callback function error
#define   IMVS_EC_ALGORITHM_OVER_MAX_MEM                    0xE000050B  // CH: ����HKA�޶�����ڴ� | EN: Maximum HKA memory reached
#define   IMVS_EC_ALGORITHM_STEP_ERR                        0xE000050C  // CH: ����STEP���� | EN: Data STEP error
#define   IMVS_EC_ALGORITHM_PARAM_INDEX                     0xE000050D  // CH: ����index���� | EN: Parameter "index" error
#define   IMVS_EC_ALGORITHM_PARAM_NUM                       0xE000050E  // CH: ������������ | EN: Incorrect number of parameters
#define   IMVS_EC_ALGORITHM_NOT_INIT                        0xE000050F  // CH: �㷨��δ��ʼ�� | EN: Algorithm library is not initialized
#define   IMVS_EC_ALGORITHM_INPUT_IMAGE_ERROR               0xE0000510  // CH: ��ȡ����ͼ��ʧ�� | EN: Failed to get input image
#define   IMVS_EC_ALGORITHM_INPUT_ROI_ERROR	                0xE0000511	// CH: ��ȡ����ROIʧ�� | EN: Failed to get input ROI
#define   IMVS_EC_ALGORITHM_INPUT_FIXTUREINFO_ERROR	        0xE0000512	// CH: ��ȡλ��������Ϣʧ�� | EN: Failed to get position correction information
#define   IMVS_EC_ALGORITHM_MODEL_EMPTY			            0xE0000513	// CH: ģ������Ϊ�� | EN: Model data is empty
#define   IMVS_EC_ALGORITHM_ROITYPE_UNKNOWN		            0xE0000514	// CH: δ�����ROI���� | EN: Undefined ROI type
#define   IMVS_EC_ALGORITHM_IMG_PATH                        0xE0000515  // CH: ��֧�ֺ����ĵ�·�� | EN: Paths with Chinese are not supported 
#define   IMVS_EC_ALGORITHM_TEACH_NOREADY                   0xE0000516  // CH: δ����ʾ����Ϣ | EN:  
#define   IMVS_EC_ALGORITHM_CALIB_NOREADY                   0xE0000517  // CH: �궨����δ��� | EN: 
#define   IMVS_EC_ALGORITHM_NOT_SUPPORT_INVERT_SELECT       0xE0000518  // CH: ��Сֵ�����ֵ��ȣ���֧�ַ�ѡ | EN: Inversion failed. The Max. value is the same with the Min. value.

/****************************************************************************
 * ����������� 0xE0000600~0xE00006FF
 * Service operation errors 0xE0000600~0xE00006FF
 ****************************************************************************/
#define   IMVS_EC_SERVICE_CREATE                            0xE0000600  // CH: ��������ʧ�� | EN: Creating service failed
#define   IMVS_EC_SERVICE_DELETE                            0xE0000601  // CH: ɾ������ʧ�� | EN: Deleting service failed
#define   IMVS_EC_SERVICE_OPEN                              0xE0000602  // CH: �򿪷���ʧ�� | EN: Opening service failed
#define   IMVS_EC_SERVICE_START                             0xE0000603  // CH: ��������ʧ�� | EN: Starting service failed
#define   IMVS_EC_SERVICE_STOP                              0xE0000604  // CH: ����ֹͣʧ�� | EN: Stopping service failed
#define   IMVS_EC_SERVICE_GET_PATH                          0xE0000605  // CH: ����·����ȡʧ�� | EN: Getting service path failed
#define   IMVS_EC_SERVICE_FIND_FILE                         0xE0000606  // CH: �����ļ�����ʧ�� | EN: Finding service file failed
#define   IMVS_EC_SERVICE_LOAD_LIBRARY                      0xE0000607  // CH: ��������ʧ�� | EN: Loading service library failed
#define   IMVS_EC_SERVICE_RETRIEVES_FUNC                    0xE0000608  // CH: ����������ʧ�� | EN: Retrieving service function failed


/****************************************************************************
 * �����Ȩ��ش��� 0xE0000700~0xE00007FF
 * Software licensing-related errors 0xE0000700~0xE00007FF
 ****************************************************************************/
#define   IMVS_EC_ENCRYPT_DONGLE_OUTDATE                    0xE0000700  // CH: ���ܹ�δ��⵽�����쳣 | EN: No dongle detected or detection exception
#define   IMVS_EC_ENCRYPT_DONGLE_OLD_EXPIRE                 0xE0000701  // CH: ���ܹ������²��һ�� | EN: Try to insert it again
#define   IMVS_EC_ENCRYPT_ALGORITHM_CHECK_FAIL              0xE0000702  // CH: �㷨������Ȩʧ�� | EN: Detecting algorithm library license failed
#define   IMVS_EC_ENCRYPT_ALGORITHM_EXPIRE                  0xE0000703  // CH: �㷨��ʹ�����ѹ� | EN: The algorithm library license is expired
#define   IMVS_EC_ENCRYPT_SOFT_OUTDATE                      0xE0000704  // CH: ����δ��⵽�����쳣 | EN: Soft lock not detected or detected exception
#define   IMVS_EC_ENCRYPT_SOFT_NOT_ACTIVATED                0xE0000705  // CH: ��Ʒ��Ȩδ���� | EN: Product authorization not activated
#define   IMVS_EC_ENCRYPT_SOFT_NOT_SUPPORT                  0xE0000706  // CH: ������֧�ֵĹ���ID | EN: Feature ID not supported by soft lock
#define   IMVS_EC_ENCRYPT_SOFT_FEATURE_EXPIRE               0xE0000707  // CH: ��Ȩ�Ĺ����ѹ��� | EN: The authorized feature has expired
#define   IMVS_EC_ENCRYPT_SOFT_ACCESS_DENIED                0xE0000708  // CH: ���ʱ��ܾ� | EN: Access denied
#define   IMVS_EC_ENCRYPT_SOFT_NO_TIME                      0xE0000709  // CH: ʱ�Ӳ����� | EN: Clock is not available
#define   IMVS_EC_ENCRYPT_SOFT_NO_DRIVER                    0xE000070A  // CH: δ��װ�����RTE | EN: Soft encryption RTE not installed
#define   IMVS_EC_ENCRYPT_SOFT_TS_DETECTED                  0xE000070B  // CH: �������ն����� | EN: The program is running at the terminal
#define   IMVS_EC_ENCRYPT_SOFT_RDP_DETECTED                 0xE000070C  // CH: ������Զ�̶����� | EN: The program is running on the remote side
#define   IMVS_EC_ENCRYPT_SOFT_VM_DETECTED                  0xE000070D  // CH: ��������������� | EN: The program is running in a virtual machine
#define   IMVS_EC_ENCRYPT_SOFT_FEATURE_NOT_FOUND            0xE000070E  // CH: ����δ�ҵ� | EN: Feature not found
#define   IMVS_EC_ENCRYPT_SOFT_INNERIMPL_ERROR              0xE000070F  // CH: �ڲ�ʵ�ִ��� | EN: Internal implementation errors
#define   IMVS_EC_ENCRYPT_SOFT_PRODUCT_NOT_FOUND            0xE0000710  // CH: ��Ʒδ�ҵ� | EN: The product was not found
#define   IMVS_EC_ENCRYPT_SOFT_RESULTS_EMPTY                0xE0000711  // CH: ��ѯ���Ϊ�� | EN: The query result is empty
#define   IMVS_EC_ENCRYPT_SOFT_ABILITY_OR_RESOURCE          0xE0000712  // CH: �򳬳�������������ڴ���Դ���㵼�»�ȡ�����Ϣʧ�� | EN: Get license information failure because of beyond the limits of capacity or applying resource failed
#define   IMVS_EC_ENCRYPT_SOFT_FEATURE_FORBIDDEN            0xE0000713  // CH: ������������ȨҪ��������� | EN: The feature is forbiddened for the machine not satisfied with authorization requirement
#define   IMVS_EC_ENCRYPT_SOFT_HASP_NOT_FOUND               0xE0000714  // CH: δ�ҵ����õı����� | EN: No available production key were found
#define   IMVS_EC_ENCRYPT_SOFT_BROKEN_SESSION               0xE0000715  // CH: �Ự�ѶϿ����糬ʱ | EN: Session is disconnected, such as timeout
#define   IMVS_EC_ENCRYPT_SOFT_COMM_ERR                     0xE0000716  // CH: ͨ�Ŵ��� | EN: Communication error
#define   IMVS_EC_ENCRYPT_WITHOUT_DEVELOP_AUTH              0xE0000717  // CH: û�п�����Ȩ�� | EN: Without development authority  
#define   IMVS_EC_ENCRYPT_CAMERA_COUNT_BEYOND               0xE0000718  // CH: ���ģ�������������� | EN: The number of camera modules is out of limit  
#define   IMVS_EC_ENCRYPT_KEY_INDOG_WRONG                   0xE0000719  // CH: У����ܹ�������ʧ��
#define   IMVS_EC_ENCRYPT_DECRYPT_FAIL_WITH_DOG             0xE000071A  // CH: ʹ�ü��ܹ������ļ�ʧ��
#define   IMVS_EC_ENCRYPT_REMOTE_DONGLE_CHECK               0xE000071B  // CH: ������У��ʧ�� | EN: Failed to verify remote dongle
#define   IMVS_EC_ENCRYPT_REMOTE_DONGLE_MAX_CONNECTION      0xE000071C  // CH: �������Ѵﵽ��󲢷���Ȩ | EN: Maximum connections of remote dongle is reached


/****************************************************************************
 * �û�Ȩ�޴��� 0xE0000800~0xE00008FF
 * User authority errors 0xE0000800~0xE00008FF
 ****************************************************************************/
#define   IMVS_EC_AUTH_SOLU_PASSWORD                        0xE0000800  // CH: ����������� | EN: Incorrect solution password
#define   IMVS_EC_AUTH_USER_PASSWORD                        0xE0000801  // CH: �û����������(Ԥ��) | EN: Incorrect user name or password (reserved)
#define   IMVS_EC_AUTH_REMOTE_NO_PASSWORD                   0xE0000802  // CH: Զ����������������
#define   IMVS_EC_AUTH_REMOTE_PASSWORD_INVALID              0xE0000803  // CH: Զ�������������
#define   IMVS_EC_AUTH_ORIGINAL_PASSWORD_INVALID            0xE0000804  // CH: ԭ�������
#define   IMVS_EC_AUTH_ASSWORD_IS_EXIST                     0xE0000805  // CH: �����Ѵ���
#define   IMVS_EC_AUTH_USER_LOCKOUT	                        0xE0000806  // CH: �û�����
#define   IMVS_EC_AUTH_NO_LOGINUSER_DATABASE_FILE           0xE0000807  // CH: û�е�¼�û������ļ�


/****************************************************************************
 * ������Ϣ 0xE0000900~0xE00009FF
 * Warning message errors 0xE0000900~0xE00009FF
 ****************************************************************************/
#define   IMVS_EC_WARN_MODULE_INPUT_SUB                     0xE0000900  // CH: ģ������δ���� | EN: The module input is not subscribed
#define   IMVS_EC_WARN_ALGORITHM                            0xE0000901  // CH: �㷨���г��־��� | EN: Warning occurred in algorithm library


/****************************************************************************
 * ģ�������ϱ� 0xE0001000~0xE00010FF
 * Module data escalation errors 0xE0001000~0xE00010FF
 ****************************************************************************/
#define   IMVS_EC_MODULE_ALGORITHM_INIT                     0xE0001000  // CH: ģ���㷨���ʼ����� | EN: Algorithmic initialization result of module
#define   IMVS_EC_MODULE_REPORT_CODE						0xE0001001  // CH: ģ��������ϱ� | EN: Report Error Code

/****************************************************************************
 * ģ����ش��� 0xE0001100~0xE00011FF
 * Model-related errors 0xE0001100~0xE00011FF
 ****************************************************************************/
#define   IMVS_EC_MODEL_OPEN                                0xE0001100  // CH: ģ���޷��� | EN: Model can't be opened
#define   IMVS_EC_MODEL_NOT_FOUND                           0xE0001101  // CH: ģ�Ͳ����� | EN: Model does not exist
#define   IMVS_EC_MODEL_FORMAT                              0xE0001102  // CH: ģ�͸�ʽ���� | EN: Model format is wrong
#define   IMVS_EC_MODEL_BE_OCCUPIED                         0xE0001103  // CH: ģ���ļ���ռ�� | EN: Model file is occupied
#define   IMVS_EC_MODEL_DATA                                0xE0001104  // CH: ģ�������쳣 | EN: Model data anomalies
#define   IMVS_EC_MODEL_DATA_LENGTH                         0xE0001105  // CH: ģ�����ݳ����쳣 | EN: The length of model data is abnormal
#define   IMVS_EC_GET_ROI_FROM_MODEL_FAIL                   0xE0001106  // CH: ��ģ���л�ȡROIʧ�� | EN: Failed to get ROI from the model file

/****************************************************************************
* ������ش��� 0xE0001200~0xE00012FF
* Model-related errors 0xE0001100~0xE00011FF
****************************************************************************/
#define   IMVS_EC_PROXY_LACK_BINARYDATA                     0xE0001200  // CH: ȱ�ٶ���������(��Ҫ�ⲿ��������) | EN: Lack the binary data
#define   IMVS_EC_PROXY_LACK_BINARYMEMORY                   0xE0001201  // CH: ȱ�ٶ������ڴ�(��Ҫ�ⲿ�����ڴ�) | EN: Lack the binary memory

#endif//end _IMVS_6000_ERROR_CODE_DEFINE_H_
