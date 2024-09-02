#ifndef _MVD_CAM_ERROR_DEFINE_H_
#define _MVD_CAM_ERROR_DEFINE_H_

//ͨ�ô����붨��:��Χ0x80000000-0x800000FF | en:
const static int MVD_CAM_E_HANDLE            = 0x80000000;  ///< �������Ч�ľ�� | en:Error or invalid handle
const static int MVD_CAM_E_SUPPORT           = 0x80000001;  ///< ��֧�ֵĹ��� | en:Not supported function
const static int MVD_CAM_E_BUFOVER           = 0x80000002;  ///< �������� | en:Cache is full
const static int MVD_CAM_E_CALLORDER         = 0x80000003;  ///< ��������˳����� | en:Function calling order error
const static int MVD_CAM_E_PARAMETER         = 0x80000004;  ///< ����Ĳ��� | en:Incorrect parameter
const static int MVD_CAM_E_RESOURCE          = 0x80000006;  ///< ��Դ����ʧ�� | en:Applying resource failed
const static int MVD_CAM_E_NODATA            = 0x80000007;  ///< ������ | en:No data
const static int MVD_CAM_E_PRECONDITION      = 0x80000008;  ///< ǰ���������󣬻����л����ѷ����仯 | en:Precondition error, or running environment changed
const static int MVD_CAM_E_VERSION           = 0x80000009;  ///< �汾��ƥ�� | en:Version mismatches
const static int MVD_CAM_E_NOENOUGH_BUF      = 0x8000000A;  ///< ������ڴ�ռ䲻�� | en:Insufficient memory
const static int MVD_CAM_E_ABNORMAL_IMAGE    = 0x8000000B;  ///< �쳣ͼ�񣬿����Ƕ�������ͼ������ | en:Abnormal image, maybe incomplete image because of lost packet
const static int MVD_CAM_E_LOAD_LIBRARY      = 0x8000000C;  ///< ��̬����DLLʧ�� | en:Load library failed
const static int MVD_CAM_E_NOOUTBUF          = 0x8000000D;  ///< û�п�����Ļ��� | en:No Avaliable Buffer
const static int MVD_CAM_E_UNKNOW            = 0x800000FF;  ///< δ֪�Ĵ��� | en:Unknown error

// GenICamϵ�д���:��Χ0x80000100-0x800001FF | en:GenICam Series Error Codes: Range from 0x80000100 to 0x800001FF
const static int MVD_CAM_E_GC_GENERIC        = 0x80000100;  ///< ͨ�ô��� | en:General error
const static int MVD_CAM_E_GC_ARGUMENT       = 0x80000101;  ///< �����Ƿ� | en:Illegal parameters
const static int MVD_CAM_E_GC_RANGE          = 0x80000102;  ///< ֵ������Χ | en:The value is out of range
const static int MVD_CAM_E_GC_PROPERTY       = 0x80000103;  ///< ���� | en:Property
const static int MVD_CAM_E_GC_RUNTIME        = 0x80000104;  ///< ���л��������� | en:Running environment error
const static int MVD_CAM_E_GC_LOGICAL        = 0x80000105;  ///< �߼����� | en:Logical error
const static int MVD_CAM_E_GC_ACCESS         = 0x80000106;  ///< �ڵ������������ | en:Node accessing condition error
const static int MVD_CAM_E_GC_TIMEOUT        = 0x80000107;  ///< ��ʱ | en:Timeout
const static int MVD_CAM_E_GC_DYNAMICCAST    = 0x80000108;  ///< ת���쳣 | en:Transformation exception
const static int MVD_CAM_E_GC_UNKNOW         = 0x800001FF;  ///< GenICamδ֪���� | en:GenICam unknown error

//GigE_STATUS��Ӧ�Ĵ�����:��Χ0x80000200-0x800002FF | en:GigE_STATUS Error Codes: Range from 0x80000200 to 0x800002FF
const static int MVD_CAM_E_NOT_IMPLEMENTED   = 0x80000200;  ///< ������豸֧�� | en:The command is not supported by device
const static int MVD_CAM_E_INVALID_ADDRESS   = 0x80000201;  ///< ���ʵ�Ŀ���ַ������ | en:The target address being accessed does not exist
const static int MVD_CAM_E_WRITE_PROTECT     = 0x80000202;  ///< Ŀ���ַ����д | en:The target address is not writable
const static int MVD_CAM_E_ACCESS_DENIED     = 0x80000203;  ///< �豸�޷���Ȩ�� | en:No permission
const static int MVD_CAM_E_BUSY              = 0x80000204;  ///< �豸æ��������Ͽ� | en:Device is busy, or network disconnected
const static int MVD_CAM_E_PACKET            = 0x80000205;  ///< ��������ݴ��� | en:Network data packet error
const static int MVD_CAM_E_NETER             = 0x80000206;  ///< ������ش��� | en:Network error
// GigE������еĴ�����
const static int MVD_CAM_E_IP_CONFLICT       = 0x80000221;  ///< �豸IP��ͻ | en:Device IP conflict

//USB_STATUS��Ӧ�Ĵ�����:��Χ0x80000300-0x800003FF | en:USB_STATUS Error Codes: Range from 0x80000300 to 0x800003FF
const static int MVD_CAM_E_USB_READ          = 0x80000300;      ///< ��usb���� | en:Reading USB error
const static int MVD_CAM_E_USB_WRITE         = 0x80000301;      ///< дusb���� | en:Writing USB error
const static int MVD_CAM_E_USB_DEVICE        = 0x80000302;      ///< �豸�쳣 | en:Device exception
const static int MVD_CAM_E_USB_GENICAM       = 0x80000303;      ///< GenICam��ش��� | en:GenICam error
const static int MVD_CAM_E_USB_BANDWIDTH     = 0x80000304;      ///< ������  �ô��������� | en:Insufficient bandwidth, this error code is newly added
const static int MVD_CAM_E_USB_DRIVER        = 0x80000305;      ///< ������ƥ�����δװ���� | en:Driver mismatch or unmounted drive
const static int MVD_CAM_E_USB_UNKNOW        = 0x800003FF;      ///< USBδ֪�Ĵ��� | en:USB unknown error

//����ʱ��Ӧ�Ĵ�����:��Χ0x80000400-0x800004FF | en:Upgrade Error Codes: Range from 0x80000400 to 0x800004FF
const static int MVD_CAM_E_UPG_FILE_MISMATCH    = 0x80000400; ///< �����̼���ƥ�� | en:Firmware mismatches
const static int MVD_CAM_E_UPG_LANGUSGE_MISMATCH = 0x80000401; ///< �����̼����Բ�ƥ�� | en:Firmware language mismatches
const static int MVD_CAM_E_UPG_CONFLICT         = 0x80000402; ///< ������ͻ���豸�Ѿ����������ٴ��������������ش˴��� | en:Upgrading conflicted (repeated upgrading requests during device upgrade)
const static int MVD_CAM_E_UPG_INNER_ERR        = 0x80000403; ///< ����ʱ����ڲ����ִ��� | en:Camera internal error during upgrade
const static int MVD_CAM_E_UPG_UNKNOW           = 0x800004FF; ///< ����ʱδ֪���� | en:Unknown error during upgrade

#endif //_MVD_CAM_ERROR_DEFINE_H_
