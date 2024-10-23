/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw.h>

#ifdef DEFINE_GUID

#ifndef FAR
# define FAR
#endif

  DEFINE_GUID(GUID_DEVINTERFACE_DISK,          0x53f56307L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_CDROM,         0x53f56308L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_PARTITION,     0x53f5630aL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_TAPE,          0x53f5630bL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_WRITEONCEDISK, 0x53f5630cL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_VOLUME,        0x53f5630dL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_MEDIUMCHANGER, 0x53f56310L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_FLOPPY,        0x53f56311L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_CDCHANGER,     0x53f56312L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_STORAGEPORT,   0x2accfe60L, 0xc130, 0x11d2, 0xb0, 0x82, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
  DEFINE_GUID(GUID_DEVINTERFACE_VMLUN,         0x6f416619L, 0x9f29, 0x42a5, 0xb2, 0x0b, 0x37, 0xe2, 0x19, 0xca, 0x02, 0xb0);
  DEFINE_GUID(GUID_DEVINTERFACE_SES,           0x1790c9ecL, 0x47d5, 0x4df3, 0xb5, 0xaf, 0x9a, 0xdf, 0x3c, 0xf2, 0x3e, 0x48);
  DEFINE_GUID(GUID_DEVINTERFACE_ZNSDISK,       0xb87941c5L, 0xffdb, 0x43c7, 0xb6, 0xb1, 0x20, 0xb6, 0x32, 0xf0, 0xb1, 0x09);

#define WDI_STORAGE_PREDICT_FAILURE_DPS_GUID {0xe9f2d03aL, 0x747c, 0x41c2, {0xbb, 0x9a, 0x02, 0xc6, 0x2b, 0x6d, 0x5f, 0xcb}};

  DEFINE_GUID(GUID_DEVINTERFACE_HIDDEN_DISK,            0x7fccc86cL, 0x228a, 0x40ad, 0x8a, 0x58, 0xf5, 0x90, 0xaf, 0x7b, 0xfd, 0xce);
  DEFINE_GUID(GUID_DEVINTERFACE_SERVICE_VOLUME,         0x6ead3d82L, 0x25ec, 0x46bc, 0xb7, 0xfd, 0xc1, 0xf0, 0xdf, 0x8f, 0x50, 0x37);
  DEFINE_GUID(GUID_DEVINTERFACE_HIDDEN_VOLUME,          0x7f108a28L, 0x9833, 0x4b3b, 0xb7, 0x80, 0x2c, 0x6b, 0x5f, 0xa5, 0xc0, 0x62);
  DEFINE_GUID(GUID_DEVINTERFACE_UNIFIED_ACCESS_RPMB,    0x27447c21L, 0xbcc3, 0x4d07, 0xa0, 0x5b, 0xa3, 0x39, 0x5b, 0xb4, 0xee, 0xe7);
  DEFINE_GUID(GUID_DEVINTERFACE_SCM_PHYSICAL_DEVICE,    0x4283609d, 0x4dc2, 0x43be, 0xbb, 0xb4, 0x4f, 0x15, 0xdf, 0xce, 0x2c, 0x61);
  DEFINE_GUID(GUID_SCM_PD_HEALTH_NOTIFICATION,          0x9da2d386, 0x72f5, 0x4ee3, 0x81, 0x55, 0xec, 0xa0, 0x67, 0x8e, 0x3b, 0x6);
  DEFINE_GUID(GUID_SCM_PD_PASSTHROUGH_INVDIMM,          0x4309AC30, 0x0D11, 0x11E4, 0x91, 0x91, 0x08, 0x00, 0x20, 0x0C, 0x9A, 0x66);
  DEFINE_GUID(GUID_DEVINTERFACE_COMPORT,                0X86E0D1E0L, 0X8089, 0X11D0, 0X9C, 0XE4, 0X08, 0X00, 0X3E, 0X30, 0X1F, 0X73);
  DEFINE_GUID(GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR, 0x4D36E978L, 0xE325, 0x11CE, 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18);

#define DiskClassGuid               GUID_DEVINTERFACE_DISK
#define CdRomClassGuid              GUID_DEVINTERFACE_CDROM
#define PartitionClassGuid          GUID_DEVINTERFACE_PARTITION
#define TapeClassGuid               GUID_DEVINTERFACE_TAPE
#define WriteOnceDiskClassGuid      GUID_DEVINTERFACE_WRITEONCEDISK
#define VolumeClassGuid             GUID_DEVINTERFACE_VOLUME
#define MediumChangerClassGuid      GUID_DEVINTERFACE_MEDIUMCHANGER
#define FloppyClassGuid             GUID_DEVINTERFACE_FLOPPY
#define CdChangerClassGuid          GUID_DEVINTERFACE_CDCHANGER
#define StoragePortClassGuid        GUID_DEVINTERFACE_STORAGEPORT
#define HiddenVolumeClassGuid       GUID_DEVINTERFACE_HIDDEN_VOLUME
#define GUID_CLASS_COMPORT          GUID_DEVINTERFACE_COMPORT
#define GUID_SERENUM_BUS_ENUMERATOR GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR

#endif  /* DEFINE_GUID */

#ifdef DEFINE_DEVPROPKEY

  DEFINE_DEVPROPKEY(DEVPKEY_Storage_Portable,         0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 2);
  DEFINE_DEVPROPKEY(DEVPKEY_Storage_Removable_Media,  0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 3);
  DEFINE_DEVPROPKEY(DEVPKEY_Storage_System_Critical,  0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 4);
  DEFINE_DEVPROPKEY(DEVPKEY_Storage_Disk_Number,      0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 5);
  DEFINE_DEVPROPKEY(DEVPKEY_Storage_Partition_Number, 0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 6);
  DEFINE_DEVPROPKEY(DEVPKEY_Storage_Mbr_Type,         0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 7);
  DEFINE_DEVPROPKEY(DEVPKEY_Storage_Gpt_Type,         0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 8);
  DEFINE_DEVPROPKEY(DEVPKEY_Storage_Gpt_Name,         0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 9);

#endif  /* DEFINE_DEVPROPKEY */

#ifndef _WINIOCTL_
#define _WINIOCTL_

#ifndef _DEVIOCTL_
#define _DEVIOCTL_

#ifndef DEVICE_TYPE
# define DEVICE_TYPE DWORD
#endif

#define FILE_DEVICE_BEEP                 0x00000001
#define FILE_DEVICE_CD_ROM               0x00000002
#define FILE_DEVICE_CD_ROM_FILE_SYSTEM   0x00000003
#define FILE_DEVICE_CONTROLLER           0x00000004
#define FILE_DEVICE_DATALINK             0x00000005
#define FILE_DEVICE_DFS                  0x00000006
#define FILE_DEVICE_DISK                 0x00000007
#define FILE_DEVICE_DISK_FILE_SYSTEM     0x00000008
#define FILE_DEVICE_FILE_SYSTEM          0x00000009
#define FILE_DEVICE_INPORT_PORT          0x0000000a
#define FILE_DEVICE_KEYBOARD             0x0000000b
#define FILE_DEVICE_MAILSLOT             0x0000000c
#define FILE_DEVICE_MIDI_IN              0x0000000d
#define FILE_DEVICE_MIDI_OUT             0x0000000e
#define FILE_DEVICE_MOUSE                0x0000000f
#define FILE_DEVICE_MULTI_UNC_PROVIDER   0x00000010
#define FILE_DEVICE_NAMED_PIPE           0x00000011
#define FILE_DEVICE_NETWORK              0x00000012
#define FILE_DEVICE_NETWORK_BROWSER      0x00000013
#define FILE_DEVICE_NETWORK_FILE_SYSTEM  0x00000014
#define FILE_DEVICE_NULL                 0x00000015
#define FILE_DEVICE_PARALLEL_PORT        0x00000016
#define FILE_DEVICE_PHYSICAL_NETCARD     0x00000017
#define FILE_DEVICE_PRINTER              0x00000018
#define FILE_DEVICE_SCANNER              0x00000019
#define FILE_DEVICE_SERIAL_MOUSE_PORT    0x0000001a
#define FILE_DEVICE_SERIAL_PORT          0x0000001b
#define FILE_DEVICE_SCREEN               0x0000001c
#define FILE_DEVICE_SOUND                0x0000001d
#define FILE_DEVICE_STREAMS              0x0000001e
#define FILE_DEVICE_TAPE                 0x0000001f
#define FILE_DEVICE_TAPE_FILE_SYSTEM     0x00000020
#define FILE_DEVICE_TRANSPORT            0x00000021
#define FILE_DEVICE_UNKNOWN              0x00000022
#define FILE_DEVICE_VIDEO                0x00000023
#define FILE_DEVICE_VIRTUAL_DISK         0x00000024
#define FILE_DEVICE_WAVE_IN              0x00000025
#define FILE_DEVICE_WAVE_OUT             0x00000026
#define FILE_DEVICE_8042_PORT            0x00000027
#define FILE_DEVICE_NETWORK_REDIRECTOR   0x00000028
#define FILE_DEVICE_BATTERY              0x00000029
#define FILE_DEVICE_BUS_EXTENDER         0x0000002a
#define FILE_DEVICE_MODEM                0x0000002b
#define FILE_DEVICE_VDM                  0x0000002c
#define FILE_DEVICE_MASS_STORAGE         0x0000002d
#define FILE_DEVICE_SMB                  0x0000002e
#define FILE_DEVICE_KS                   0x0000002f
#define FILE_DEVICE_CHANGER              0x00000030
#define FILE_DEVICE_SMARTCARD            0x00000031
#define FILE_DEVICE_ACPI                 0x00000032
#define FILE_DEVICE_DVD                  0x00000033
#define FILE_DEVICE_FULLSCREEN_VIDEO     0x00000034
#define FILE_DEVICE_DFS_FILE_SYSTEM      0x00000035
#define FILE_DEVICE_DFS_VOLUME           0x00000036
#define FILE_DEVICE_SERENUM              0x00000037
#define FILE_DEVICE_TERMSRV              0x00000038
#define FILE_DEVICE_KSEC                 0x00000039
#define FILE_DEVICE_FIPS                 0x0000003A
#define FILE_DEVICE_INFINIBAND           0x0000003B
#define FILE_DEVICE_VMBUS                0x0000003E
#define FILE_DEVICE_CRYPT_PROVIDER       0x0000003F
#define FILE_DEVICE_WPD                  0x00000040
#define FILE_DEVICE_BLUETOOTH            0x00000041
#define FILE_DEVICE_MT_COMPOSITE         0x00000042
#define FILE_DEVICE_MT_TRANSPORT         0x00000043
#define FILE_DEVICE_BIOMETRIC            0x00000044
#define FILE_DEVICE_PMI                  0x00000045
#define FILE_DEVICE_EHSTOR               0x00000046
#define FILE_DEVICE_DEVAPI               0x00000047
#define FILE_DEVICE_GPIO                 0x00000048
#define FILE_DEVICE_USBEX                0x00000049
#define FILE_DEVICE_CONSOLE              0x00000050
#define FILE_DEVICE_NFP                  0x00000051
#define FILE_DEVICE_SYSENV               0x00000052
#define FILE_DEVICE_VIRTUAL_BLOCK        0x00000053
#define FILE_DEVICE_POINT_OF_SERVICE     0x00000054
#define FILE_DEVICE_STORAGE_REPLICATION  0x00000055
#define FILE_DEVICE_TRUST_ENV            0x00000056
#define FILE_DEVICE_UCM                  0x00000057
#define FILE_DEVICE_UCMTCPCI             0x00000058
#define FILE_DEVICE_PERSISTENT_MEMORY    0x00000059
#define FILE_DEVICE_NVDIMM               0x0000005a
#define FILE_DEVICE_HOLOGRAPHIC          0x0000005b
#define FILE_DEVICE_SDFXHCI              0x0000005c
#define FILE_DEVICE_UCMUCSI              0x0000005d
#define FILE_DEVICE_PRM                  0x0000005e
#define FILE_DEVICE_EVENT_COLLECTOR      0x0000005f
#define FILE_DEVICE_USB4                 0x00000060
#define FILE_DEVICE_SOUNDWIRE            0x00000061
#define FILE_DEVICE_FABRIC_NVME          0x00000062
#define FILE_DEVICE_SVM                  0x00000063
#define FILE_DEVICE_HARDWARE_ACCELERATOR 0x00000064
#define FILE_DEVICE_I3C                  0x00000065

#define CTL_CODE(DeviceType, Function, Method, Access) (((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method))

#define DEVICE_TYPE_FROM_CTL_CODE(ctrlCode) (((DWORD)(ctrlCode & 0xffff0000)) >> 16)
#define METHOD_FROM_CTL_CODE(ctrlCode)      ((DWORD)(ctrlCode & 3))

#define METHOD_BUFFERED   0
#define METHOD_IN_DIRECT  1
#define METHOD_OUT_DIRECT 2
#define METHOD_NEITHER    3

#define METHOD_DIRECT_TO_HARDWARE   METHOD_IN_DIRECT
#define METHOD_DIRECT_FROM_HARDWARE METHOD_OUT_DIRECT

#define FILE_ANY_ACCESS     0
#define FILE_SPECIAL_ACCESS (FILE_ANY_ACCESS)
#define FILE_READ_ACCESS    (0x0001)
#define FILE_WRITE_ACCESS   (0x0002)

#endif  /* _DEVIOCTL_ */

#ifndef _NTDDSTOR_H_
#define _NTDDSTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#define IOCTL_STORAGE_BASE FILE_DEVICE_MASS_STORAGE

#define IOCTL_STORAGE_CHECK_VERIFY                      CTL_CODE(IOCTL_STORAGE_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_CHECK_VERIFY2                     CTL_CODE(IOCTL_STORAGE_BASE, 0x0200, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_MEDIA_REMOVAL                     CTL_CODE(IOCTL_STORAGE_BASE, 0x0201, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_EJECT_MEDIA                       CTL_CODE(IOCTL_STORAGE_BASE, 0x0202, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_LOAD_MEDIA                        CTL_CODE(IOCTL_STORAGE_BASE, 0x0203, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_LOAD_MEDIA2                       CTL_CODE(IOCTL_STORAGE_BASE, 0x0203, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_RESERVE                           CTL_CODE(IOCTL_STORAGE_BASE, 0x0204, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_RELEASE                           CTL_CODE(IOCTL_STORAGE_BASE, 0x0205, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_FIND_NEW_DEVICES                  CTL_CODE(IOCTL_STORAGE_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_EJECTION_CONTROL                  CTL_CODE(IOCTL_STORAGE_BASE, 0x0250, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_MCN_CONTROL                       CTL_CODE(IOCTL_STORAGE_BASE, 0x0251, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_MEDIA_TYPES                   CTL_CODE(IOCTL_STORAGE_BASE, 0x0300, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_MEDIA_TYPES_EX                CTL_CODE(IOCTL_STORAGE_BASE, 0x0301, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_MEDIA_SERIAL_NUMBER           CTL_CODE(IOCTL_STORAGE_BASE, 0x0304, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_HOTPLUG_INFO                  CTL_CODE(IOCTL_STORAGE_BASE, 0x0305, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_SET_HOTPLUG_INFO                  CTL_CODE(IOCTL_STORAGE_BASE, 0x0306, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_RESET_BUS                         CTL_CODE(IOCTL_STORAGE_BASE, 0x0400, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_RESET_DEVICE                      CTL_CODE(IOCTL_STORAGE_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_BREAK_RESERVATION                 CTL_CODE(IOCTL_STORAGE_BASE, 0x0405, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_PERSISTENT_RESERVE_IN             CTL_CODE(IOCTL_STORAGE_BASE, 0x0406, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_PERSISTENT_RESERVE_OUT            CTL_CODE(IOCTL_STORAGE_BASE, 0x0407, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_GET_DEVICE_NUMBER                 CTL_CODE(IOCTL_STORAGE_BASE, 0x0420, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_DEVICE_NUMBER_EX              CTL_CODE(IOCTL_STORAGE_BASE, 0x0421, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_PREDICT_FAILURE                   CTL_CODE(IOCTL_STORAGE_BASE, 0x0440, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_FAILURE_PREDICTION_CONFIG         CTL_CODE(IOCTL_STORAGE_BASE, 0x0441, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_COUNTERS                      CTL_CODE(IOCTL_STORAGE_BASE, 0x442, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_READ_CAPACITY                     CTL_CODE(IOCTL_STORAGE_BASE, 0x0450, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_GET_DEVICE_TELEMETRY              CTL_CODE(IOCTL_STORAGE_BASE, 0x0470, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_DEVICE_TELEMETRY_NOTIFY           CTL_CODE(IOCTL_STORAGE_BASE, 0x0471, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_DEVICE_TELEMETRY_QUERY_CAPS       CTL_CODE(IOCTL_STORAGE_BASE, 0x0472, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_GET_DEVICE_TELEMETRY_RAW          CTL_CODE(IOCTL_STORAGE_BASE, 0x0473, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD         CTL_CODE(IOCTL_STORAGE_BASE, 0x0480, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_PROTOCOL_COMMAND                  CTL_CODE(IOCTL_STORAGE_BASE, 0x04F0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_SET_PROPERTY                      CTL_CODE(IOCTL_STORAGE_BASE, 0x04FF, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_QUERY_PROPERTY                    CTL_CODE(IOCTL_STORAGE_BASE, 0x0500, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES        CTL_CODE(IOCTL_STORAGE_BASE, 0x0501, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES CTL_CODE(IOCTL_STORAGE_BASE, 0x0502, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_REINITIALIZE_MEDIA                CTL_CODE(IOCTL_STORAGE_BASE, 0x0590, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_GET_BC_PROPERTIES                 CTL_CODE(IOCTL_STORAGE_BASE, 0x0600, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_STORAGE_ALLOCATE_BC_STREAM                CTL_CODE(IOCTL_STORAGE_BASE, 0x0601, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_FREE_BC_STREAM                    CTL_CODE(IOCTL_STORAGE_BASE, 0x0602, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT       CTL_CODE(IOCTL_STORAGE_BASE, 0x0620, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_START_DATA_INTEGRITY_CHECK        CTL_CODE(IOCTL_STORAGE_BASE, 0x0621, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_STOP_DATA_INTEGRITY_CHECK         CTL_CODE(IOCTL_STORAGE_BASE, 0x0622, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define OBSOLETE_IOCTL_STORAGE_RESET_BUS                CTL_CODE(IOCTL_STORAGE_BASE, 0x0400, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define OBSOLETE_IOCTL_STORAGE_RESET_DEVICE             CTL_CODE(IOCTL_STORAGE_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_FIRMWARE_GET_INFO                 CTL_CODE(IOCTL_STORAGE_BASE, 0x0700, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_FIRMWARE_DOWNLOAD                 CTL_CODE(IOCTL_STORAGE_BASE, 0x0701, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_FIRMWARE_ACTIVATE                 CTL_CODE(IOCTL_STORAGE_BASE, 0x0702, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_ENABLE_IDLE_POWER                 CTL_CODE(IOCTL_STORAGE_BASE, 0x0720, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_IDLE_POWERUP_REASON           CTL_CODE(IOCTL_STORAGE_BASE, 0x0721, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_POWER_ACTIVE                      CTL_CODE(IOCTL_STORAGE_BASE, 0x0722, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_POWER_IDLE                        CTL_CODE(IOCTL_STORAGE_BASE, 0x0723, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_EVENT_NOTIFICATION                CTL_CODE(IOCTL_STORAGE_BASE, 0x0724, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_DEVICE_POWER_CAP                  CTL_CODE(IOCTL_STORAGE_BASE, 0x0725, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_RPMB_COMMAND                      CTL_CODE(IOCTL_STORAGE_BASE, 0x0726, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_ATTRIBUTE_MANAGEMENT              CTL_CODE(IOCTL_STORAGE_BASE, 0x0727, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_STORAGE_DIAGNOSTIC                        CTL_CODE(IOCTL_STORAGE_BASE, 0x0728, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS       CTL_CODE(IOCTL_STORAGE_BASE, 0x0729, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_REMOVE_ELEMENT_AND_TRUNCATE       CTL_CODE(IOCTL_STORAGE_BASE, 0x0730, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG           CTL_CODE(IOCTL_STORAGE_BASE, 0x0731, METHOD_BUFFERED, FILE_ANY_ACCESS)

  typedef struct _STORAGE_HOTPLUG_INFO
  {
    DWORD   Size;
    BOOLEAN MediaRemovable;
    BOOLEAN MediaHotplug;
    BOOLEAN DeviceHotplug;
    BOOLEAN WriteCacheEnableOverride;
  } STORAGE_HOTPLUG_INFO, *PSTORAGE_HOTPLUG_INFO;

  typedef struct _STORAGE_DEVICE_NUMBER
  {
    DEVICE_TYPE DeviceType;
    DWORD       DeviceNumber;
    DWORD       PartitionNumber;
  } STORAGE_DEVICE_NUMBER, *PSTORAGE_DEVICE_NUMBER;

  typedef struct _STORAGE_DEVICE_NUMBERS
  {
    DWORD                 Version;
    DWORD                 Size;
    DWORD                 NumberOfDevices;
    STORAGE_DEVICE_NUMBER Devices[ANYSIZE_ARRAY];
  } STORAGE_DEVICE_NUMBERS, *PSTORAGE_DEVICE_NUMBERS;

#define STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_CONFLICT 0x1
#define STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_NOHWID   0x2
#define STORAGE_DEVICE_FLAGS_PAGE_83_DEVICEGUID                0x4

  typedef struct _STORAGE_DEVICE_NUMBER_EX
  {
    DWORD       Version;
    DWORD       Size;
    DWORD       Flags;
    DEVICE_TYPE DeviceType;
    DWORD       DeviceNumber;
    GUID        DeviceGuid;
    DWORD       PartitionNumber;
  } STORAGE_DEVICE_NUMBER_EX, *PSTORAGE_DEVICE_NUMBER_EX;

  typedef struct _STORAGE_BUS_RESET_REQUEST
  {
    BYTE PathId;
  } STORAGE_BUS_RESET_REQUEST, *PSTORAGE_BUS_RESET_REQUEST;

  typedef struct STORAGE_BREAK_RESERVATION_REQUEST
  {
    DWORD  Length;
    BYTE  _unused;
    BYTE   PathId;
    BYTE   TargetId;
    BYTE   Lun;
  } STORAGE_BREAK_RESERVATION_REQUEST, *PSTORAGE_BREAK_RESERVATION_REQUEST;

  typedef struct _PREVENT_MEDIA_REMOVAL
  {
    BOOLEAN PreventMediaRemoval;
  } PREVENT_MEDIA_REMOVAL, *PPREVENT_MEDIA_REMOVAL;

  typedef struct _CLASS_MEDIA_CHANGE_CONTEXT
  {
    DWORD MediaChangeCount;
    DWORD NewState;
  } CLASS_MEDIA_CHANGE_CONTEXT, *PCLASS_MEDIA_CHANGE_CONTEXT;

  typedef struct _TAPE_STATISTICS
  {
    DWORD         Version;
    DWORD         Flags;
    LARGE_INTEGER RecoveredWrites;
    LARGE_INTEGER UnrecoveredWrites;
    LARGE_INTEGER RecoveredReads;
    LARGE_INTEGER UnrecoveredReads;
    BYTE          CompressionRatioReads;
    BYTE          CompressionRatioWrites;
  } TAPE_STATISTICS, *PTAPE_STATISTICS;

#define RECOVERED_WRITES_VALID       0x00000001
#define UNRECOVERED_WRITES_VALID     0x00000002
#define RECOVERED_READS_VALID        0x00000004
#define UNRECOVERED_READS_VALID      0x00000008
#define WRITE_COMPRESSION_INFO_VALID 0x00000010
#define READ_COMPRESSION_INFO_VALID  0x00000020

  typedef struct _TAPE_GET_STATISTICS
  {
    DWORD Operation;
  } TAPE_GET_STATISTICS, *PTAPE_GET_STATISTICS;

#define TAPE_RETURN_STATISTICS 0L
#define TAPE_RETURN_ENV_INFO   1L
#define TAPE_RESET_STATISTICS  2L

  typedef enum _STORAGE_MEDIA_TYPE
  {
    DDS_4mm = 0x20,
    MiniQic,
    Travan,
    QIC,
    MP_8mm,
    AME_8mm,
    AIT1_8mm,
    DLT,
    NCTP,
    IBM_3480,
    IBM_3490E,
    IBM_Magstar_3590,
    IBM_Magstar_MP,
    STK_DATA_D3,
    SONY_DTF,
    DV_6mm,
    DMI,
    SONY_D2,
    CLEANER_CARTRIDGE,
    CD_ROM,
    CD_R,
    CD_RW,
    DVD_ROM,
    DVD_R,
    DVD_RW,
    MO_3_RW,
    MO_5_WO,
    MO_5_RW,
    MO_5_LIMDOW,
    PC_5_WO,
    PC_5_RW,
    PD_5_RW,
    ABL_5_WO,
    PINNACLE_APEX_5_RW,
    SONY_12_WO,
    PHILIPS_12_WO,
    HITACHI_12_WO,
    CYGNET_12_WO,
    KODAK_14_WO,
    MO_NFR_525,
    NIKON_12_RW,
    IOMEGA_ZIP,
    IOMEGA_JAZ,
    SYQUEST_EZ135,
    SYQUEST_EZFLYER,
    SYQUEST_SYJET,
    AVATAR_F2,
    MP2_8mm,
    DST_S,
    DST_M,
    DST_L,
    VXATape_1,
    VXATape_2,
    STK_9840,
    LTO_Ultrium,
    LTO_Accelis,
    DVD_RAM,
    AIT_8mm,
    ADR_1,
    ADR_2,
    STK_9940,
    SAIT,
    VXATape
  } STORAGE_MEDIA_TYPE, *PSTORAGE_MEDIA_TYPE;

#define MEDIA_ERASEABLE         0x00000001
#define MEDIA_WRITE_ONCE        0x00000002
#define MEDIA_READ_ONLY         0x00000004
#define MEDIA_READ_WRITE        0x00000008
#define MEDIA_WRITE_PROTECTED   0x00000100
#define MEDIA_CURRENTLY_MOUNTED 0x80000000

  typedef enum _STORAGE_BUS_TYPE
  {
    BusTypeUnknown = 0x00,
    BusTypeScsi,
    BusTypeAtapi,
    BusTypeAta,
    BusType1394,
    BusTypeSsa,
    BusTypeFibre,
    BusTypeUsb,
    BusTypeRAID,
    BusTypeiScsi,
    BusTypeSas,
    BusTypeSata,
    BusTypeSd,
    BusTypeMmc,
    BusTypeVirtual,
    BusTypeFileBackedVirtual,
    BusTypeSpaces,
    BusTypeNvme,
    BusTypeSCM,
    BusTypeUfs,
    BusTypeNvmeof,
    BusTypeMax,
    BusTypeMaxReserved = 0x7F
  } STORAGE_BUS_TYPE, *PSTORAGE_BUS_TYPE;

#define SupportsDeviceSharing(BusType) ((BusType == BusTypeScsi) || (BusType == BusTypeFibre) || (BusType == BusTypeiScsi) || (BusType == BusTypeSas) || (BusType == BusTypeSpaces))

  typedef struct _DEVICE_MEDIA_INFO
  {
    union
    {
      struct
      {
        LARGE_INTEGER      Cylinders;
        STORAGE_MEDIA_TYPE MediaType;
        DWORD              TracksPerCylinder;
        DWORD              SectorsPerTrack;
        DWORD              BytesPerSector;
        DWORD              NumberMediaSides;
        DWORD              MediaCharacteristics;
      } DiskInfo;
      struct
      {
        LARGE_INTEGER      Cylinders;
        STORAGE_MEDIA_TYPE MediaType;
        DWORD              TracksPerCylinder;
        DWORD              SectorsPerTrack;
        DWORD              BytesPerSector;
        DWORD              NumberMediaSides;
        DWORD              MediaCharacteristics;
      } RemovableDiskInfo;
      struct
      {
        STORAGE_MEDIA_TYPE MediaType;
        DWORD              MediaCharacteristics;
        DWORD              CurrentBlockSize;
        STORAGE_BUS_TYPE   BusType;
        union
        {
          struct
          {
            BYTE MediumType;
            BYTE DensityCode;
          } ScsiInformation;
        } BusSpecificData;
      } TapeInfo;
    } DeviceSpecific;
  } DEVICE_MEDIA_INFO, *PDEVICE_MEDIA_INFO;

  typedef struct _GET_MEDIA_TYPES
  {
    DWORD             DeviceType;
    DWORD             MediaInfoCount;
    DEVICE_MEDIA_INFO MediaInfo[1];
  } GET_MEDIA_TYPES, *PGET_MEDIA_TYPES;

  typedef struct _STORAGE_PREDICT_FAILURE
  {
    DWORD PredictFailure;
    BYTE  VendorSpecific[512];
  } STORAGE_PREDICT_FAILURE, *PSTORAGE_PREDICT_FAILURE;

  typedef struct _STORAGE_FAILURE_PREDICTION_CONFIG
  {
    DWORD   Version;
    DWORD   Size;
    BOOLEAN Set;
    BOOLEAN Enabled;
    WORD    Reserved;
  } STORAGE_FAILURE_PREDICTION_CONFIG, *PSTORAGE_FAILURE_PREDICTION_CONFIG;

#define STORAGE_FAILURE_PREDICTION_CONFIG_V1 1

  typedef enum _STORAGE_QUERY_TYPE
  {
    PropertyStandardQuery = 0,
    PropertyExistsQuery,
    PropertyMaskQuery,
    PropertyQueryMaxDefined
  } STORAGE_QUERY_TYPE, *PSTORAGE_QUERY_TYPE;

  typedef enum _STORAGE_SET_TYPE
  {
    PropertyStandardSet = 0,
    PropertyExistsSet,
    PropertySetMaxDefined
  } STORAGE_SET_TYPE, *PSTORAGE_SET_TYPE;

  typedef enum _STORAGE_PROPERTY_ID
  {
    StorageDeviceProperty = 0,
    StorageAdapterProperty,
    StorageDeviceIdProperty,
    StorageDeviceUniqueIdProperty,
    StorageDeviceWriteCacheProperty,
    StorageMiniportProperty,
    StorageAccessAlignmentProperty,
    StorageDeviceSeekPenaltyProperty,
    StorageDeviceTrimProperty,
    StorageDeviceWriteAggregationProperty,
    StorageDeviceDeviceTelemetryProperty,
    StorageDeviceLBProvisioningProperty,
    StorageDevicePowerProperty,
    StorageDeviceCopyOffloadProperty,
    StorageDeviceResiliencyProperty,
    StorageDeviceMediumProductType,
    StorageAdapterRpmbProperty,
    StorageAdapterCryptoProperty,
    StorageDeviceIoCapabilityProperty = 48,
    StorageAdapterProtocolSpecificProperty,
    StorageDeviceProtocolSpecificProperty,
    StorageAdapterTemperatureProperty,
    StorageDeviceTemperatureProperty,
    StorageAdapterPhysicalTopologyProperty,
    StorageDevicePhysicalTopologyProperty,
    StorageDeviceAttributesProperty,
    StorageDeviceManagementStatus,
    StorageAdapterSerialNumberProperty,
    StorageDeviceLocationProperty,
    StorageDeviceNumaProperty,
    StorageDeviceZonedDeviceProperty,
    StorageDeviceUnsafeShutdownCount,
    StorageDeviceEnduranceProperty,
    StorageDeviceLedStateProperty,
    StorageDeviceSelfEncryptionProperty = 64,
    StorageFruIdProperty,
    StorageStackProperty,
    StorageAdapterProtocolSpecificPropertyEx,
    StorageDeviceProtocolSpecificPropertyEx,
  } STORAGE_PROPERTY_ID, *PSTORAGE_PROPERTY_ID;

  typedef struct _STORAGE_PROPERTY_QUERY
  {
    STORAGE_PROPERTY_ID PropertyId;
    STORAGE_QUERY_TYPE  QueryType;
    BYTE                AdditionalParameters[1];
  } STORAGE_PROPERTY_QUERY, *PSTORAGE_PROPERTY_QUERY;

  typedef struct _STORAGE_PROPERTY_SET
  {
    STORAGE_PROPERTY_ID PropertyId;
    STORAGE_SET_TYPE    SetType;
    BYTE                AdditionalParameters[1];
  } STORAGE_PROPERTY_SET, *PSTORAGE_PROPERTY_SET;

  typedef struct _STORAGE_DESCRIPTOR_HEADER
  {
    DWORD Version;
    DWORD Size;
  } STORAGE_DESCRIPTOR_HEADER, *PSTORAGE_DESCRIPTOR_HEADER;

  typedef struct _STORAGE_DEVICE_DESCRIPTOR
  {
    DWORD            Version;
    DWORD            Size;
    BYTE             DeviceType;
    BYTE             DeviceTypeModifier;
    BOOLEAN          RemovableMedia;
    BOOLEAN          CommandQueueing;
    DWORD            VendorIdOffset;
    DWORD            ProductIdOffset;
    DWORD            ProductRevisionOffset;
    DWORD            SerialNumberOffset;
    STORAGE_BUS_TYPE BusType;
    DWORD            RawPropertiesLength;
    BYTE             RawDeviceProperties[1];
  } STORAGE_DEVICE_DESCRIPTOR, *PSTORAGE_DEVICE_DESCRIPTOR;

  typedef struct _STORAGE_ADAPTER_DESCRIPTOR
  {
    DWORD   Version;
    DWORD   Size;
    DWORD   MaximumTransferLength;
    DWORD   MaximumPhysicalPages;
    DWORD   AlignmentMask;
    BOOLEAN AdapterUsesPio;
    BOOLEAN AdapterScansDown;
    BOOLEAN CommandQueueing;
    BOOLEAN AcceleratedTransfer;
    BYTE    BusType;
    WORD    BusMajorVersion;
    WORD    BusMinorVersion;
    BYTE    SrbType;
    BYTE    AddressType;
  } STORAGE_ADAPTER_DESCRIPTOR, *PSTORAGE_ADAPTER_DESCRIPTOR;

#define NO_SRBTYPE_ADAPTER_DESCRIPTOR_SIZE UFIELD_OFFSET(STORAGE_ADAPTER_DESCRIPTOR, SrbType)

#ifndef SRB_TYPE_SCSI_REQUEST_BLOCK
# define SRB_TYPE_SCSI_REQUEST_BLOCK 0
#endif

#ifndef SRB_TYPE_STORAGE_REQUEST_BLOCK
# define SRB_TYPE_STORAGE_REQUEST_BLOCK 1
#endif

#ifndef STORAGE_ADDRESS_TYPE_BTL8
# define STORAGE_ADDRESS_TYPE_BTL8 0
#endif

  typedef struct _STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR
  {
    DWORD Version;
    DWORD Size;
    DWORD BytesPerCacheLine;
    DWORD BytesOffsetForCacheAlignment;
    DWORD BytesPerLogicalSector;
    DWORD BytesPerPhysicalSector;
    DWORD BytesOffsetForSectorAlignment;
  } STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR, *PSTORAGE_ACCESS_ALIGNMENT_DESCRIPTOR;

  typedef struct _STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR
  {
    DWORD Version;
    DWORD Size;
    DWORD MediumProductType;
  } STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR, *PSTORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR;

  typedef enum _STORAGE_PORT_CODE_SET
  {
    StoragePortCodeSetReserved  = 0,
    StoragePortCodeSetStorport  = 1,
    StoragePortCodeSetSCSIport  = 2,
    StoragePortCodeSetSpaceport = 3,
    StoragePortCodeSetATAport   = 4,
    StoragePortCodeSetUSBport   = 5,
    StoragePortCodeSetSBP2port  = 6,
    StoragePortCodeSetSDport    = 7
  } STORAGE_PORT_CODE_SET, *PSTORAGE_PORT_CODE_SET;

#define STORAGE_MINIPORT_DESCRIPTOR_V1_SIZE RTL_SIZEOF_THROUGH_FIELD(STORAGE_MINIPORT_DESCRIPTOR, IoTimeoutValue)

  typedef struct _STORAGE_MINIPORT_DESCRIPTOR
  {
    DWORD                 Version;
    DWORD                 Size;
    STORAGE_PORT_CODE_SET Portdriver;
    BOOLEAN               LUNResetSupported;
    BOOLEAN               TargetResetSupported;
    WORD                  IoTimeoutValue;
    BOOLEAN               ExtraIoInfoSupported;
    union
    {
      __C89_NAMELESS struct
      {
        BYTE LogicalPoFxForDisk : 1;
        BYTE ForwardIo          : 1;
        BYTE Reserved           : 6;
      } DUMMYSTRUCTNAME;
      BYTE AsBYTE;
    } Flags;
    BYTE  Reserved0[2];
    DWORD Reserved1;
  } STORAGE_MINIPORT_DESCRIPTOR, *PSTORAGE_MINIPORT_DESCRIPTOR;

  typedef enum _STORAGE_IDENTIFIER_CODE_SET
  {
    StorageIdCodeSetReserved = 0,
    StorageIdCodeSetBinary   = 1,
    StorageIdCodeSetAscii    = 2,
    StorageIdCodeSetUtf8     = 3
  } STORAGE_IDENTIFIER_CODE_SET, *PSTORAGE_IDENTIFIER_CODE_SET;

  typedef enum _STORAGE_IDENTIFIER_TYPE
  {
    StorageIdTypeVendorSpecific           = 0,
    StorageIdTypeVendorId                 = 1,
    StorageIdTypeEUI64                    = 2,
    StorageIdTypeFCPHName                 = 3,
    StorageIdTypePortRelative             = 4,
    StorageIdTypeTargetPortGroup          = 5,
    StorageIdTypeLogicalUnitGroup         = 6,
    StorageIdTypeMD5LogicalUnitIdentifier = 7,
    StorageIdTypeScsiNameString           = 8
  } STORAGE_IDENTIFIER_TYPE, *PSTORAGE_IDENTIFIER_TYPE;

#define StorageIdTypeNAA StorageIdTypeFCPHName

  typedef enum _STORAGE_ID_NAA_FORMAT
  {
    StorageIdNAAFormatIEEEExtended            = 2,
    StorageIdNAAFormatIEEERegistered          = 3,
    StorageIdNAAFormatIEEEERegisteredExtended = 5
  } STORAGE_ID_NAA_FORMAT, *PSTORAGE_ID_NAA_FORMAT;

  typedef enum _STORAGE_ASSOCIATION_TYPE
  {
    StorageIdAssocDevice = 0,
    StorageIdAssocPort   = 1,
    StorageIdAssocTarget = 2
  } STORAGE_ASSOCIATION_TYPE, *PSTORAGE_ASSOCIATION_TYPE;

  typedef struct _STORAGE_IDENTIFIER
  {
    STORAGE_IDENTIFIER_CODE_SET CodeSet;
    STORAGE_IDENTIFIER_TYPE     Type;
    WORD                        IdentifierSize;
    WORD                        NextOffset;
    STORAGE_ASSOCIATION_TYPE    Association;
    BYTE                        Identifier[1];
  } STORAGE_IDENTIFIER, *PSTORAGE_IDENTIFIER;

  typedef struct _STORAGE_DEVICE_ID_DESCRIPTOR
  {
    DWORD Version;
    DWORD Size;
    DWORD NumberOfIdentifiers;
    BYTE  Identifiers[1];
  } STORAGE_DEVICE_ID_DESCRIPTOR, *PSTORAGE_DEVICE_ID_DESCRIPTOR;

  typedef struct _DEVICE_SEEK_PENALTY_DESCRIPTOR
  {
    DWORD   Version;
    DWORD   Size;
    BOOLEAN IncursSeekPenalty;
  } DEVICE_SEEK_PENALTY_DESCRIPTOR, *PDEVICE_SEEK_PENALTY_DESCRIPTOR;

  typedef struct _DEVICE_WRITE_AGGREGATION_DESCRIPTOR
  {
    ULONG   Version;
    ULONG   Size;
    BOOLEAN BenefitsFromWriteAggregation;
  } DEVICE_WRITE_AGGREGATION_DESCRIPTOR, *PDEVICE_WRITE_AGGREGATION_DESCRIPTOR;

  typedef struct _DEVICE_TRIM_DESCRIPTOR
  {
    DWORD   Version;
    DWORD   Size;
    BOOLEAN TrimEnabled;
  } DEVICE_TRIM_DESCRIPTOR, *PDEVICE_TRIM_DESCRIPTOR;

  typedef struct _DEVICE_LB_PROVISIONING_DESCRIPTOR
  {
    DWORD     Version;
    DWORD     Size;
    BYTE      ThinProvisioningEnabled        : 1;
    BYTE      ThinProvisioningReadZeros      : 1;
    BYTE      AnchorSupported                : 3;
    BYTE      UnmapGranularityAlignmentValid : 1;
    BYTE      GetFreeSpaceSupported          : 1;
    BYTE      MapSupported                   : 1;
    BYTE      Reserved1[7];
    DWORDLONG OptimalUnmapGranularity;
    DWORDLONG UnmapGranularityAlignment;
    DWORD     MaxUnmapLbaCount;
    DWORD     MaxUnmapBlockDescriptorCount;
  } DEVICE_LB_PROVISIONING_DESCRIPTOR, *PDEVICE_LB_PROVISIONING_DESCRIPTOR;

#define DEVICE_LB_PROVISIONING_DESCRIPTOR_V1_SIZE RTL_SIZEOF_THROUGH_FIELD(DEVICE_LB_PROVISIONING_DESCRIPTOR, UnmapGranularityAlignment)

  typedef struct _STORAGE_LB_PROVISIONING_MAP_RESOURCES
  {
    DWORD     Size;
    DWORD     Version;
    BYTE      AvailableMappingResourcesValid : 1;
    BYTE      UsedMappingResourcesValid      : 1;
    BYTE      Reserved0                      : 6;
    BYTE      Reserved1[3];
    BYTE      AvailableMappingResourcesScope : 2;
    BYTE      UsedMappingResourcesScope      : 2;
    BYTE      Reserved2                      : 4;
    BYTE      Reserved3[3];
    DWORDLONG AvailableMappingResources;
    DWORDLONG UsedMappingResources;
  } STORAGE_LB_PROVISIONING_MAP_RESOURCES, *PSTORAGE_LB_PROVISIONING_MAP_RESOURCES;

  typedef struct _DEVICE_POWER_DESCRIPTOR
  {
    DWORD   Version;
    DWORD   Size;
    BOOLEAN DeviceAttentionSupported;
    BOOLEAN AsynchronousNotificationSupported;
    BOOLEAN IdlePowerManagementEnabled;
    BOOLEAN D3ColdEnabled;
    BOOLEAN D3ColdSupported;
    BOOLEAN NoVerifyDuringIdlePower;
    BYTE    Reserved[2];
    DWORD   IdleTimeoutInMS;
  } DEVICE_POWER_DESCRIPTOR, *PDEVICE_POWER_DESCRIPTOR;

  typedef struct _DEVICE_COPY_OFFLOAD_DESCRIPTOR
  {
    DWORD     Version;
    DWORD     Size;
    DWORD     MaximumTokenLifetime;
    DWORD     DefaultTokenLifetime;
    DWORDLONG MaximumTransferSize;
    DWORDLONG OptimalTransferCount;
    DWORD     MaximumDataDescriptors;
    DWORD     MaximumTransferLengthPerDescriptor;
    DWORD     OptimalTransferLengthPerDescriptor;
    WORD      OptimalTransferLengthGranularity;
    BYTE      Reserved[2];
  } DEVICE_COPY_OFFLOAD_DESCRIPTOR, *PDEVICE_COPY_OFFLOAD_DESCRIPTOR;

  typedef struct _STORAGE_DEVICE_RESILIENCY_DESCRIPTOR
  {
    DWORD Version;
    DWORD Size;
    DWORD NameOffset;
    DWORD NumberOfLogicalCopies;
    DWORD NumberOfPhysicalCopies;
    DWORD PhysicalDiskRedundancy;
    DWORD NumberOfColumns;
    DWORD Interleave;
  } STORAGE_DEVICE_RESILIENCY_DESCRIPTOR, *PSTORAGE_DEVICE_RESILIENCY_DESCRIPTOR;

  typedef enum _STORAGE_RPMB_FRAME_TYPE
  {
    StorageRpmbFrameTypeUnknown = 0,
    StorageRpmbFrameTypeStandard,
    StorageRpmbFrameTypeMax
  } STORAGE_RPMB_FRAME_TYPE, *PSTORAGE_RPMB_FRAME_TYPE;

#define STORAGE_RPMB_DESCRIPTOR_VERSION_1        1
#define STORAGE_RPMB_MINIMUM_RELIABLE_WRITE_SIZE 512

  typedef struct _STORAGE_RPMB_DESCRIPTOR
  {
    DWORD                   Version;
    DWORD                   Size;
    DWORD                   SizeInBytes;
    DWORD                   MaxReliableWriteSizeInBytes;
    STORAGE_RPMB_FRAME_TYPE FrameFormat;
  } STORAGE_RPMB_DESCRIPTOR, *PSTORAGE_RPMB_DESCRIPTOR;

  typedef enum _STORAGE_CRYPTO_ALGORITHM_ID
  {
    StorageCryptoAlgorithmUnknown = 0,
    StorageCryptoAlgorithmXTSAES = 1,
    StorageCryptoAlgorithmBitlockerAESCBC,
    StorageCryptoAlgorithmAESECB,
    StorageCryptoAlgorithmESSIVAESCBC,
    StorageCryptoAlgorithmMax
  } STORAGE_CRYPTO_ALGORITHM_ID, *PSTORAGE_CRYPTO_ALGORITHM_ID;

  typedef enum _STORAGE_CRYPTO_KEY_SIZE
  {
    StorageCryptoKeySizeUnknown = 0,
    StorageCryptoKeySize128Bits = 1,
    StorageCryptoKeySize192Bits,
    StorageCryptoKeySize256Bits,
    StorageCryptoKeySize512Bits
  } STORAGE_CRYPTO_KEY_SIZE, *PSTORAGE_CRYPTO_KEY_SIZE;

#define STORAGE_CRYPTO_CAPABILITY_VERSION_1 1

  typedef struct _STORAGE_CRYPTO_CAPABILITY
  {
    DWORD                       Version;
    DWORD                       Size;
    DWORD                       CryptoCapabilityIndex;
    STORAGE_CRYPTO_ALGORITHM_ID AlgorithmId;
    STORAGE_CRYPTO_KEY_SIZE     KeySize;
    DWORD                       DataUnitSizeBitmask;
  } STORAGE_CRYPTO_CAPABILITY, *PSTORAGE_CRYPTO_CAPABILITY;

#define STORAGE_CRYPTO_CAPABILITY_VERSION_2 2

  typedef struct _STORAGE_CRYPTO_CAPABILITY_V2
  {
    DWORD                       Version;
    DWORD                       Size;
    DWORD                       CryptoCapabilityIndex;
    STORAGE_CRYPTO_ALGORITHM_ID AlgorithmId;
    STORAGE_CRYPTO_KEY_SIZE     KeySize;
    DWORD                       DataUnitSizeBitmask;
    WORD                        MaxIVBitSize;
    WORD                        Reserved;
    union
    {
      __C89_NAMELESS struct
      {
        BYTE FIPS     : 1;
        BYTE Reserved : 7;
      };
      BYTE AsUchar;
    } SecurityComplianceBitmask;
  } STORAGE_CRYPTO_CAPABILITY_V2, *PSTORAGE_CRYPTO_CAPABILITY_V2;

#define STORAGE_CRYPTO_DESCRIPTOR_VERSION_1 1

  typedef struct _STORAGE_CRYPTO_DESCRIPTOR
  {
    DWORD                     Version;
    DWORD                     Size;
    DWORD                     NumKeysSupported;
    DWORD                     NumCryptoCapabilities;
    STORAGE_CRYPTO_CAPABILITY CryptoCapabilities[ANYSIZE_ARRAY];
  } STORAGE_CRYPTO_DESCRIPTOR, *PSTORAGE_CRYPTO_DESCRIPTOR;

#define STORAGE_CRYPTO_DESCRIPTOR_VERSION_2 2

  typedef enum _STORAGE_ICE_TYPE
  {
    StorageIceTypeUnknown = 0,
    StorageIceTypeUfs,
    StorageIceTypeNvme,
  } STORAGE_ICE_TYPE, *PSTORAGE_ICE_TYPE;

  typedef struct _STORAGE_CRYPTO_DESCRIPTOR_V2
  {
    DWORD            Version;
    DWORD            Size;
    DWORD            NumKeysSupported;
    DWORD            NumCryptoCapabilities;
    STORAGE_ICE_TYPE IceType;
    union
    {
      __C89_NAMELESS struct
      {
        BYTE FIPS     : 1;
        BYTE Reserved : 7;
      };
      BYTE AsUchar;
    } SecurityComplianceBitmask;
    STORAGE_CRYPTO_CAPABILITY_V2 CryptoCapabilities[ANYSIZE_ARRAY];
  } STORAGE_CRYPTO_DESCRIPTOR_V2, *PSTORAGE_CRYPTO_DESCRIPTOR_V2;

#define STORAGE_TIER_NAME_LENGTH        (256)
#define STORAGE_TIER_DESCRIPTION_LENGTH (512)

#define STORAGE_TIER_FLAG_NO_SEEK_PENALTY  (0x00020000)
#define STORAGE_TIER_FLAG_WRITE_BACK_CACHE (0x00200000)
#define STORAGE_TIER_FLAG_READ_CACHE       (0x00400000)
#define STORAGE_TIER_FLAG_PARITY           (0x00800000)
#define STORAGE_TIER_FLAG_SMR              (0x01000000)

  typedef enum _STORAGE_TIER_MEDIA_TYPE
  {
    StorageTierMediaTypeUnspecified = 0,
    StorageTierMediaTypeDisk        = 1,
    StorageTierMediaTypeSsd         = 2,
    StorageTierMediaTypeScm         = 4,
    StorageTierMediaTypeMax
  } STORAGE_TIER_MEDIA_TYPE, *PSTORAGE_TIER_MEDIA_TYPE;

  typedef enum _STORAGE_TIER_CLASS
  {
    StorageTierClassUnspecified = 0,
    StorageTierClassCapacity,
    StorageTierClassPerformance,
    StorageTierClassMax
  } STORAGE_TIER_CLASS, *PSTORAGE_TIER_CLASS;

  typedef struct _STORAGE_TIER
  {
    GUID                    Id;
    WCHAR                   Name[STORAGE_TIER_NAME_LENGTH];
    WCHAR                   Description[STORAGE_TIER_NAME_LENGTH];
    DWORDLONG               Flags;
    DWORDLONG               ProvisionedCapacity;
    STORAGE_TIER_MEDIA_TYPE MediaType;
    STORAGE_TIER_CLASS      Class;
  } STORAGE_TIER, *PSTORAGE_TIER;

  typedef struct _STORAGE_DEVICE_TIERING_DESCRIPTOR
  {
    DWORD        Version;
    DWORD        Size;
    DWORD        Flags;
    DWORD        TotalNumberOfTiers;
    DWORD        NumberOfTiersReturned;
    STORAGE_TIER Tiers[ANYSIZE_ARRAY];
  } STORAGE_DEVICE_TIERING_DESCRIPTOR, *PSTORAGE_DEVICE_TIERING_DESCRIPTOR;

  typedef struct _STORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR
  {
    DWORD Version;
    DWORD Size;
    DWORD NumberOfFaultDomains;
    GUID  FaultDomainIds[ANYSIZE_ARRAY];
  } STORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR, *PSTORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR;

  typedef enum _STORAGE_PROTOCOL_TYPE
  {
    ProtocolTypeUnknown     = 0x00,
    ProtocolTypeScsi,
    ProtocolTypeAta,
    ProtocolTypeNvme,
    ProtocolTypeSd,
    ProtocolTypeUfs,
    ProtocolTypeProprietary = 0x7E,
    ProtocolTypeMaxReserved = 0x7F
  } STORAGE_PROTOCOL_TYPE, *PSTORAGE_PROTOCOL_TYPE;

  typedef enum _STORAGE_PROTOCOL_NVME_DATA_TYPE
  {
    NVMeDataTypeUnknown = 0,
    NVMeDataTypeIdentify,
    NVMeDataTypeLogPage,
    NVMeDataTypeFeature,
    NVMeDataTypeLogPageEx,
    NVMeDataTypeFeatureEx,
  } STORAGE_PROTOCOL_NVME_DATA_TYPE, *PSTORAGE_PROTOCOL_NVME_DATA_TYPE;

  typedef enum _STORAGE_PROTOCOL_ATA_DATA_TYPE
  {
    AtaDataTypeUnknown = 0,
    AtaDataTypeIdentify,
    AtaDataTypeLogPage
  } STORAGE_PROTOCOL_ATA_DATA_TYPE, *PSTORAGE_PROTOCOL_ATA_DATA_TYPE;

  typedef enum _STORAGE_PROTOCOL_UFS_DATA_TYPE
  {
    UfsDataTypeUnknown = 0,
    UfsDataTypeQueryDescriptor,
    UfsDataTypeQueryAttribute,
    UfsDataTypeQueryFlag,
    UfsDataTypeQueryDmeAttribute,
    UfsDataTypeQueryDmePeerAttribute,
    UfsDataTypeMax
  } STORAGE_PROTOCOL_UFS_DATA_TYPE, *PSTORAGE_PROTOCOL_UFS_DATA_TYPE;

  typedef union _STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE
  {
    __C89_NAMELESS struct
    {
      DWORD RetainAsynEvent  : 1;
      DWORD LogSpecificField : 4;
      DWORD Reserved0        : 3;
      DWORD UUIDIndex        : 7;
      DWORD Reserved         : 17;
    };
    DWORD AsUlong;
  } STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE, *PSTORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE;

  typedef struct _STORAGE_PROTOCOL_SPECIFIC_DATA
  {
    STORAGE_PROTOCOL_TYPE ProtocolType;
    DWORD                 DataType;
    DWORD                 ProtocolDataRequestValue;
    DWORD                 ProtocolDataRequestSubValue;
    DWORD                 ProtocolDataOffset;
    DWORD                 ProtocolDataLength;
    DWORD                 FixedProtocolReturnData;
    DWORD                 ProtocolDataRequestSubValue2;
    DWORD                 ProtocolDataRequestSubValue3;
    DWORD                 ProtocolDataRequestSubValue4;
  } STORAGE_PROTOCOL_SPECIFIC_DATA, *PSTORAGE_PROTOCOL_SPECIFIC_DATA;

  typedef struct _STORAGE_PROTOCOL_SPECIFIC_DATA_EXT
  {
    STORAGE_PROTOCOL_TYPE ProtocolType;
    DWORD                 DataType;
    DWORD                 ProtocolDataValue;
    DWORD                 ProtocolDataSubValue;
    DWORD                 ProtocolDataOffset;
    DWORD                 ProtocolDataLength;
    DWORD                 FixedProtocolReturnData;
    DWORD                 ProtocolDataSubValue2;
    DWORD                 ProtocolDataSubValue3;
    DWORD                 ProtocolDataSubValue4;
    DWORD                 ProtocolDataSubValue5;
    DWORD                 ProtocolDataSubValue6;
    DWORD                 Reserved[4];
  } STORAGE_PROTOCOL_SPECIFIC_DATA_EXT, *PSTORAGE_PROTOCOL_SPECIFIC_DATA_EXT;

  typedef struct _STORAGE_PROTOCOL_DATA_DESCRIPTOR
  {
    DWORD                          Version;
    DWORD                          Size;
    STORAGE_PROTOCOL_SPECIFIC_DATA ProtocolSpecificData;
  } STORAGE_PROTOCOL_DATA_DESCRIPTOR, *PSTORAGE_PROTOCOL_DATA_DESCRIPTOR;

  typedef struct _STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT
  {
    DWORD                              Version;
    DWORD                              Size;
    STORAGE_PROTOCOL_SPECIFIC_DATA_EXT ProtocolSpecificData;
  } STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT, *PSTORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT;

#define STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT_VERSION 1
#define STORAGE_TEMPERATURE_VALUE_NOT_REPORTED       0x8000

  typedef struct _STORAGE_TEMPERATURE_INFO
  {
    WORD    Index;
    SHORT   Temperature;
    SHORT   OverThreshold;
    SHORT   UnderThreshold;
    BOOLEAN OverThresholdChangable;
    BOOLEAN UnderThresholdChangable;
    BOOLEAN EventGenerated;
    BYTE    Reserved0;
    DWORD   Reserved1;
  } STORAGE_TEMPERATURE_INFO, *PSTORAGE_TEMPERATURE_INFO;

  typedef struct _STORAGE_TEMPERATURE_DATA_DESCRIPTOR
  {
    DWORD                    Version;
    DWORD                    Size;
    SHORT                    CriticalTemperature;
    SHORT                    WarningTemperature;
    WORD                     InfoCount;
    BYTE                     Reserved0[2];
    DWORD                    Reserved1[2];
    STORAGE_TEMPERATURE_INFO TemperatureInfo[ANYSIZE_ARRAY];
  } STORAGE_TEMPERATURE_DATA_DESCRIPTOR, *PSTORAGE_TEMPERATURE_DATA_DESCRIPTOR;

#define STORAGE_TEMPERATURE_THRESHOLD_FLAG_ADAPTER_REQUEST 0x0001

  typedef struct _STORAGE_TEMPERATURE_THRESHOLD
  {
    DWORD   Version;
    DWORD   Size;
    WORD    Flags;
    WORD    Index;
    SHORT   Threshold;
    BOOLEAN OverThreshold;
    BYTE    Reserved;
  } STORAGE_TEMPERATURE_THRESHOLD, *PSTORAGE_TEMPERATURE_THRESHOLD;

#define STORAGE_COMPONENT_ROLE_CACHE   0x00000001
#define STORAGE_COMPONENT_ROLE_TIERING 0x00000002
#define STORAGE_COMPONENT_ROLE_DATA    0x00000004

  typedef enum _STORAGE_DEVICE_FORM_FACTOR
  {
    FormFactorUnknown = 0,
    FormFactor3_5,
    FormFactor2_5,
    FormFactor1_8,
    FormFactor1_8Less,
    FormFactorEmbedded,
    FormFactorMemoryCard,
    FormFactormSata,
    FormFactorM_2,
    FormFactorPCIeBoard,
    FormFactorDimm,
  } STORAGE_DEVICE_FORM_FACTOR, *PSTORAGE_DEVICE_FORM_FACTOR;

  typedef enum _STORAGE_COMPONENT_HEALTH_STATUS
  {
    HealthStatusUnknown = 0,
    HealthStatusNormal,
    HealthStatusThrottled,
    HealthStatusWarning,
    HealthStatusDisabled,
    HealthStatusFailed,
  } STORAGE_COMPONENT_HEALTH_STATUS, *PSTORAGE_COMPONENT_HEALTH_STATUS;

  typedef union _STORAGE_SPEC_VERSION
  {
    __C89_NAMELESS struct
    {
      union
      {
        __C89_NAMELESS struct
        {
          BYTE SubMinor;
          BYTE Minor;
        } DUMMYSTRUCTNAME;
        WORD AsUshort;
      } MinorVersion;
      WORD MajorVersion;
    } DUMMYSTRUCTNAME;
    DWORD AsUlong;
  } STORAGE_SPEC_VERSION, *PSTORAGE_SPEC_VERSION;

  typedef struct _STORAGE_PHYSICAL_DEVICE_DATA
  {
    DWORD                           DeviceId;
    DWORD                           Role;
    STORAGE_COMPONENT_HEALTH_STATUS HealthStatus;
    STORAGE_PROTOCOL_TYPE           CommandProtocol;
    STORAGE_SPEC_VERSION            SpecVersion;
    STORAGE_DEVICE_FORM_FACTOR      FormFactor;
    BYTE                            Vendor[8];
    BYTE                            Model[40];
    BYTE                            FirmwareRevision[16];
    DWORDLONG                       Capacity;
    BYTE                            PhysicalLocation[32];
    DWORD                           Reserved[2];
  } STORAGE_PHYSICAL_DEVICE_DATA, *PSTORAGE_PHYSICAL_DEVICE_DATA;

  typedef struct _STORAGE_PHYSICAL_ADAPTER_DATA
  {
    DWORD                           AdapterId;
    STORAGE_COMPONENT_HEALTH_STATUS HealthStatus;
    STORAGE_PROTOCOL_TYPE           CommandProtocol;
    STORAGE_SPEC_VERSION            SpecVersion;
    BYTE                            Vendor[8];
    BYTE                            Model[40];
    BYTE                            FirmwareRevision[16];
    BYTE                            PhysicalLocation[32];
    BOOLEAN                         ExpanderConnected;
    BYTE                            Reserved0[3];
    DWORD                           Reserved1[3];
  } STORAGE_PHYSICAL_ADAPTER_DATA, *PSTORAGE_PHYSICAL_ADAPTER_DATA;

  typedef struct _STORAGE_PHYSICAL_NODE_DATA
  {
    DWORD NodeId;
    DWORD AdapterCount;
    DWORD AdapterDataLength;
    DWORD AdapterDataOffset;
    DWORD DeviceCount;
    DWORD DeviceDataLength;
    DWORD DeviceDataOffset;
    DWORD Reserved[3];
  } STORAGE_PHYSICAL_NODE_DATA, *PSTORAGE_PHYSICAL_NODE_DATA;

  typedef struct _STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR
  {
    DWORD                      Version;
    DWORD                      Size;
    DWORD                      NodeCount;
    DWORD                      Reserved;
    STORAGE_PHYSICAL_NODE_DATA Node[ANYSIZE_ARRAY];
  } STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR, *PSTORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR;

  typedef struct _STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR
  {
    DWORD Version;
    DWORD Size;
    DWORD LunMaxIoCount;
    DWORD AdapterMaxIoCount;
  } STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR, *PSTORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR;

  typedef struct _STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR
  {
    DWORD   Version;
    DWORD   Size;
    DWORD64 Attributes;
  } STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR, *PSTORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR;

#define STORAGE_ATTRIBUTE_BYTE_ADDRESSABLE_IO      0x01
#define STORAGE_ATTRIBUTE_BLOCK_IO                 0x02
#define STORAGE_ATTRIBUTE_DYNAMIC_PERSISTENCE      0x04
#define STORAGE_ATTRIBUTE_VOLATILE                 0x08
#define STORAGE_ATTRIBUTE_ASYNC_EVENT_NOTIFICATION 0x10
#define STORAGE_ATTRIBUTE_PERF_SIZE_INDEPENDENT    0x20

  typedef enum _STORAGE_DISK_HEALTH_STATUS
  {
    DiskHealthUnknown = 0,
    DiskHealthUnhealthy,
    DiskHealthWarning,
    DiskHealthHealthy,
    DiskHealthMax
  } STORAGE_DISK_HEALTH_STATUS, *PSTORAGE_DISK_HEALTH_STATUS;

  typedef enum _STORAGE_DISK_OPERATIONAL_STATUS
  {
    DiskOpStatusNone = 0,
    DiskOpStatusUnknown,
    DiskOpStatusOk,
    DiskOpStatusPredictingFailure,
    DiskOpStatusInService,
    DiskOpStatusHardwareError,
    DiskOpStatusNotUsable,
    DiskOpStatusTransientError,
    DiskOpStatusMissing,
  } STORAGE_DISK_OPERATIONAL_STATUS, *PSTORAGE_DISK_OPERATIONAL_STATUS;

  typedef enum _STORAGE_OPERATIONAL_STATUS_REASON
  {
    DiskOpReasonUnknown = 0,
    DiskOpReasonScsiSenseCode,
    DiskOpReasonMedia,
    DiskOpReasonIo,
    DiskOpReasonThresholdExceeded,
    DiskOpReasonLostData,
    DiskOpReasonEnergySource,
    DiskOpReasonConfiguration,
    DiskOpReasonDeviceController,
    DiskOpReasonMediaController,
    DiskOpReasonComponent,
    DiskOpReasonNVDIMM_N,
    DiskOpReasonBackgroundOperation,
    DiskOpReasonInvalidFirmware,
    DiskOpReasonHealthCheck,
    DiskOpReasonLostDataPersistence,
    DiskOpReasonDisabledByPlatform,
    DiskOpReasonLostWritePersistence,
    DiskOpReasonDataPersistenceLossImminent,
    DiskOpReasonWritePersistenceLossImminent,
    DiskOpReasonMax
  } STORAGE_OPERATIONAL_STATUS_REASON, *PSTORAGE_OPERATIONAL_STATUS_REASON;

  typedef struct _STORAGE_OPERATIONAL_REASON
  {
    DWORD                             Version;
    DWORD                             Size;
    STORAGE_OPERATIONAL_STATUS_REASON Reason;
    union
    {
      struct
      {
        BYTE SenseKey;
        BYTE ASC;
        BYTE ASCQ;
        BYTE Reserved;
      } ScsiSenseKey;
      struct
      {
        BYTE CriticalHealth;
        BYTE ModuleHealth[2];
        BYTE ErrorThresholdStatus;
      } NVDIMM_N;
      DWORD AsUlong;
    } RawBytes;
  } STORAGE_OPERATIONAL_REASON, *PSTORAGE_OPERATIONAL_REASON;

#define STORAGE_DEVICE_MAX_OPERATIONAL_STATUS 16

  typedef struct _STORAGE_DEVICE_MANAGEMENT_STATUS
  {
    DWORD                           Version;
    DWORD                           Size;
    STORAGE_DISK_HEALTH_STATUS      Health;
    DWORD                           NumberOfOperationalStatus;
    DWORD                           NumberOfAdditionalReasons;
    STORAGE_DISK_OPERATIONAL_STATUS OperationalStatus[STORAGE_DEVICE_MAX_OPERATIONAL_STATUS];
    STORAGE_OPERATIONAL_REASON      AdditionalReasons[ANYSIZE_ARRAY];
  } STORAGE_DEVICE_MANAGEMENT_STATUS, *PSTORAGE_DEVICE_MANAGEMENT_STATUS;

#define STORAGE_ADAPTER_SERIAL_NUMBER_V1_MAX_LENGTH (128)

  typedef struct _STORAGE_ADAPTER_SERIAL_NUMBER
  {
    DWORD Version;
    DWORD Size;
    WCHAR SerialNumber[STORAGE_ADAPTER_SERIAL_NUMBER_V1_MAX_LENGTH];
  } STORAGE_ADAPTER_SERIAL_NUMBER, *PSTORAGE_ADAPTER_SERIAL_NUMBER;

#define STORAGE_ADAPTER_SERIAL_NUMBER_V1_VERSION (sizeof(STORAGE_ADAPTER_SERIAL_NUMBER))
#define STORAGE_ADAPTER_SERIAL_NUMBER_V1_SIZE    (sizeof(STORAGE_ADAPTER_SERIAL_NUMBER))

  typedef enum _STORAGE_ZONED_DEVICE_TYPES
  {
    ZonedDeviceTypeUnknown = 0,
    ZonedDeviceTypeHostManaged,
    ZonedDeviceTypeHostAware,
    ZonedDeviceTypeDeviceManaged,
  } STORAGE_ZONED_DEVICE_TYPES, *PSTORAGE_ZONED_DEVICE_TYPES;

  typedef enum _STORAGE_ZONE_TYPES
  {
    ZoneTypeUnknown                  = 0,
    ZoneTypeConventional             = 1,
    ZoneTypeSequentialWriteRequired  = 2,
    ZoneTypeSequentialWritePreferred = 3,
    ZoneTypeMax
  } STORAGE_ZONE_TYPES, *PSTORAGE_ZONE_TYPES;

  typedef struct _STORAGE_ZONE_GROUP
  {
    DWORD              ZoneCount;
    STORAGE_ZONE_TYPES ZoneType;
    DWORDLONG          ZoneSize;
  } STORAGE_ZONE_GROUP, *PSTORAGE_ZONE_GROUP;

  typedef struct _STORAGE_ZONED_DEVICE_DESCRIPTOR
  {
    DWORD                      Version;
    DWORD                      Size;
    STORAGE_ZONED_DEVICE_TYPES DeviceType;
    DWORD                      ZoneCount;
    union
    {
      struct
      {
        DWORD   MaxOpenZoneCount;
        BOOLEAN UnrestrictedRead;
        BYTE    Reserved[3];
      } SequentialRequiredZone;
      struct
      {
        DWORD OptimalOpenZoneCount;
        DWORD Reserved;
      } SequentialPreferredZone;
    } ZoneAttributes;
    DWORD              ZoneGroupCount;
    STORAGE_ZONE_GROUP ZoneGroup[ANYSIZE_ARRAY];
  } STORAGE_ZONED_DEVICE_DESCRIPTOR, *PSTORAGE_ZONED_DEVICE_DESCRIPTOR;

  typedef struct _DEVICE_LOCATION
  {
    DWORD Socket;
    DWORD Slot;
    DWORD Adapter;
    DWORD Port;
    __C89_NAMELESS union
    {
      __C89_NAMELESS struct
      {
        DWORD Channel;
        DWORD Device;
      } DUMMYSTRUCTNAME;
      __C89_NAMELESS struct
      {
        DWORD Target;
        DWORD Lun;
      } DUMMYSTRUCTNAME2;
    } DUMMYUNIONNAME;
  } DEVICE_LOCATION, *PDEVICE_LOCATION;

  typedef struct _STORAGE_DEVICE_LOCATION_DESCRIPTOR
  {
    DWORD           Version;
    DWORD           Size;
    DEVICE_LOCATION Location;
    DWORD           StringOffset;
  } STORAGE_DEVICE_LOCATION_DESCRIPTOR, *PSTORAGE_DEVICE_LOCATION_DESCRIPTOR;

  typedef struct _STORAGE_DEVICE_NUMA_PROPERTY
  {
    DWORD Version;
    DWORD Size;
    DWORD NumaNode;
  } STORAGE_DEVICE_NUMA_PROPERTY, *PSTORAGE_DEVICE_NUMA_PROPERTY;

#define STORAGE_DEVICE_NUMA_NODE_UNKNOWN MAXDWORD

  typedef struct _STORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT
  {
    DWORD Version;
    DWORD Size;
    DWORD UnsafeShutdownCount;
  } STORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT, *PSTORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT;

  typedef struct _STORAGE_HW_ENDURANCE_INFO
  {
    DWORD ValidFields;
    DWORD GroupId;
    struct
    {
      DWORD Shared   : 1;
      DWORD Reserved : 31;
    } Flags;
    DWORD LifePercentage;
    BYTE  BytesReadCount[16];
    BYTE  ByteWriteCount[16];
  } STORAGE_HW_ENDURANCE_INFO, *PSTORAGE_HW_ENDURANCE_INFO;

  typedef struct _STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR
  {
    DWORD                     Version;
    DWORD                     Size;
    STORAGE_HW_ENDURANCE_INFO EnduranceInfo;
  } STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR, *PSTORAGE_HW_ENDURANCE_DATA_DESCRIPTOR;

  typedef enum _STORAGE_STACK_TYPE
  {
    StorageStackTypeUnknown = 0,
    StorageStackTypeScsi,
    StorageStackTypeNVMe,
  } STORAGE_STACK_TYPE, *PSTORAGE_STACK_TYPE;

  typedef struct _STORAGE_STACK_DESCRIPTOR
  {
    DWORD              Version;
    DWORD              Size;
    STORAGE_STACK_TYPE StorageStackType;
  } STORAGE_STACK_DESCRIPTOR, *PSTORAGE_STACK_DESCRIPTOR;

  typedef struct _STORAGE_DEVICE_LED_STATE_DESCRIPTOR
  {
    DWORD     Version;
    DWORD     Size;
    DWORDLONG State;
  } STORAGE_DEVICE_LED_STATE_DESCRIPTOR, *PSTORAGE_DEVICE_LED_STATE_DESCRIPTOR;

  typedef struct _STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY
  {
    DWORD   Version;
    DWORD   Size;
    BOOLEAN SupportsSelfEncryption;
  } STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY, *PSTORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY;

  typedef enum _STORAGE_ENCRYPTION_TYPE
  {
    StorageEncryptionTypeUnknown = 0x00,
    StorageEncryptionTypeEDrive  = 0x01,
    StorageEncryptionTypeTcgOpal = 0x02,
  } STORAGE_ENCRYPTION_TYPE, *PSTORAGE_ENCRYPTION_TYPE;

  typedef struct _STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2
  {
    DWORD                   Version;
    DWORD                   Size;
    BOOLEAN                 SupportsSelfEncryption;
    STORAGE_ENCRYPTION_TYPE EncryptionType;
  } STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2, *PSTORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2;

  typedef struct _STORAGE_FRU_ID_DESCRIPTOR
  {
    DWORD Version;
    DWORD Size;
    DWORD IdentifierSize;
    BYTE  Identifier[ANYSIZE_ARRAY];
  } STORAGE_FRU_ID_DESCRIPTOR, *PSTORAGE_FRU_ID_DESCRIPTOR;

  typedef DWORD DEVICE_DATA_MANAGEMENT_SET_ACTION, DEVICE_DSM_ACTION;

#define DeviceDsmActionFlag_NonDestructive      (0x80000000)
#define IsDsmActionNonDestructive(_Action)      ((BOOLEAN)((_Action & DeviceDsmActionFlag_NonDestructive) != 0))
#define DeviceDsmAction_None                    (0x00000000u)
#define DeviceDsmAction_Trim                    (0x00000001u)
#define DeviceDsmAction_Notification            (0x00000002u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_OffloadRead             (0x00000003u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_OffloadWrite            (0x00000004u)
#define DeviceDsmAction_Allocation              (0x00000005u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_Repair                  (0x00000006u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_Scrub                   (0x00000007u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_DrtQuery                (0x00000008u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_DrtClear                (0x00000009u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_DrtDisable              (0x0000000Au | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_TieringQuery            (0x0000000Bu | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_Map                     (0x0000000Cu | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_RegenerateParity        (0x0000000Du | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_NvCache_Change_Priority (0x0000000Eu | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_NvCache_Evict           (0x0000000Fu | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_TopologyIdQuery         (0x00000010u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_GetPhysicalAddresses    (0x00000011u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_ScopeRegen              (0x00000012u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_ReportZones             (0x00000013u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_OpenZone                (0x00000014u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_FinishZone              (0x00000015u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_CloseZone               (0x00000016u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_ResetWritePointer       (0x00000017u)
#define DeviceDsmAction_GetRangeErrorInfo       (0x00000018u | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_WriteZeroes             (0x00000019u)
#define DeviceDsmAction_LostQuery               (0x0000001Au | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_GetFreeSpace            (0x0000001Bu | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_ConversionQuery         (0x0000001Cu | DeviceDsmActionFlag_NonDestructive)
#define DeviceDsmAction_VdtSet                  (0x0000001Du)
#define DeviceDsmAction_QueryPreferLocalRepair  (0x0000001Eu | DeviceDsmActionFlag_NonDestructive)
#define DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE   0x00000001

  typedef struct _DEVICE_DATA_SET_RANGE
  {
    LONGLONG  StartingOffset;
    DWORDLONG LengthInBytes;
  } DEVICE_DATA_SET_RANGE, *PDEVICE_DATA_SET_RANGE,
    DEVICE_DSM_RANGE,      *PDEVICE_DSM_RANGE;

  typedef struct _DEVICE_MANAGE_DATA_SET_ATTRIBUTES
  {
    DWORD                             Size;
    DEVICE_DATA_MANAGEMENT_SET_ACTION Action;
    DWORD                             Flags;
    DWORD                             ParameterBlockOffset;
    DWORD                             ParameterBlockLength;
    DWORD                             DataSetRangesOffset;
    DWORD                             DataSetRangesLength;
  } DEVICE_MANAGE_DATA_SET_ATTRIBUTES, *PDEVICE_MANAGE_DATA_SET_ATTRIBUTES,
    DEVICE_DSM_INPUT,                  *PDEVICE_DSM_INPUT;

  typedef struct _DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT
  {
    DWORD             Size;
    DEVICE_DSM_ACTION Action;
    DWORD             Flags;
    DWORD             OperationStatus;
    DWORD             ExtendedError;
    DWORD             TargetDetailedError;
    DWORD             ReservedStatus;
    DWORD             OutputBlockOffset;
    DWORD             OutputBlockLength;
  } DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT, *PDEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT,
    DEVICE_DSM_OUTPUT,                        *PDEVICE_DSM_OUTPUT;

  typedef struct _DEVICE_DSM_DEFINITION
  {
    DEVICE_DSM_ACTION Action;
    BOOLEAN           SingleRange;
    DWORD             ParameterBlockAlignment;
    DWORD             ParameterBlockLength;
    BOOLEAN           HasOutput;
    DWORD             OutputBlockAlignment;
    DWORD             OutputBlockLength;
  } DEVICE_DSM_DEFINITION, *PDEVICE_DSM_DEFINITION;

#define DeviceDsmDefinition_None              {DeviceDsmAction_None, FALSE, 0, 0, FALSE, 0, 0}
#define DEVICE_DSM_FLAG_TRIM_NOT_FS_ALLOCATED 0x80000000
#define DEVICE_DSM_FLAG_TRIM_BYPASS_RZAT      0x40000000
#define DeviceDsmDefinition_Trim              {DeviceDsmAction_Trim, FALSE, 0, 0, FALSE, 0, 0}
#define DEVICE_DSM_NOTIFY_FLAG_BEGIN          0x00000001
#define DEVICE_DSM_NOTIFY_FLAG_END            0x00000002
#define DeviceDsmDefinition_Notification      {DeviceDsmAction_Notification, FALSE, __alignof__(DEVICE_DSM_NOTIFICATION_PARAMETERS), sizeof(DEVICE_DSM_NOTIFICATION_PARAMETERS), FALSE, 0, 0}

  typedef struct _DEVICE_DSM_NOTIFICATION_PARAMETERS
  {
    DWORD Size;
    DWORD Flags;
    DWORD NumFileTypeIDs;
    GUID  FileTypeID[ANYSIZE_ARRAY];
  } DEVICE_DSM_NOTIFICATION_PARAMETERS, *PDEVICE_DSM_NOTIFICATION_PARAMETERS;

#define STORAGE_OFFLOAD_MAX_TOKEN_LENGTH     512
#define STORAGE_OFFLOAD_TOKEN_ID_LENGTH      0x1F8
#define STORAGE_OFFLOAD_TOKEN_TYPE_ZERO_DATA 0xFFFF0001

  typedef struct _STORAGE_OFFLOAD_TOKEN
  {
    BYTE TokenType[4];
    BYTE Reserved[2];
    BYTE TokenIdLength[2];
    __C89_NAMELESS union
    {
      struct
      {
        BYTE Reserved2[STORAGE_OFFLOAD_TOKEN_ID_LENGTH];
      } StorageOffloadZeroDataToken;
      BYTE Token[STORAGE_OFFLOAD_TOKEN_ID_LENGTH];
    } DUMMYUNIONNAME;
  } STORAGE_OFFLOAD_TOKEN, *PSTORAGE_OFFLOAD_TOKEN;

#define MAKE_ZERO_TOKEN(T)                                \
  (                                                       \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[0]     = 0xFF, \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[1]     = 0xFF, \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[2]     = 0x00, \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[3]     = 0x01, \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenIdLength[0] = 0x01, \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenIdLength[1] = 0xF8  \
  )

#define IS_ZERO_TOKEN(T)                                     \
  ((                                                         \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[0]     == 0xFF && \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[1]     == 0xFF && \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[2]     == 0x00 && \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenType[3]     == 0x01 && \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenIdLength[0] == 0x01 && \
    ((PSTORAGE_OFFLOAD_TOKEN)T)->TokenIdLength[1] == 0xF8    \
  ))

  typedef struct _DEVICE_DSM_OFFLOAD_READ_PARAMETERS
  {
    DWORD Flags;
    DWORD TimeToLive;
    DWORD Reserved[2];
  } DEVICE_DSM_OFFLOAD_READ_PARAMETERS, *PDEVICE_DSM_OFFLOAD_READ_PARAMETERS;

#define STORAGE_OFFLOAD_READ_RANGE_TRUNCATED 0x00000001

  typedef struct _STORAGE_OFFLOAD_READ_OUTPUT
  {
    DWORD                 OffloadReadFlags;
    DWORD                 Reserved;
    DWORDLONG             LengthProtected;
    DWORD                 TokenLength;
    STORAGE_OFFLOAD_TOKEN Token;
  } STORAGE_OFFLOAD_READ_OUTPUT, *PSTORAGE_OFFLOAD_READ_OUTPUT;

#define DeviceDsmDefinition_OffloadRead              \
  {                                                  \
    DeviceDsmAction_OffloadRead,                     \
    FALSE,                                           \
    __alignof__(DEVICE_DSM_OFFLOAD_READ_PARAMETERS), \
    sizeof(DEVICE_DSM_OFFLOAD_READ_PARAMETERS),      \
    FALSE,                                           \
    __alignof__(STORAGE_OFFLOAD_READ_OUTPUT),        \
    sizeof(STORAGE_OFFLOAD_READ_OUTPUT)              \
  }

  typedef struct _DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS
  {
    DWORD                 Flags;
    DWORD                 Reserved;
    DWORDLONG             TokenOffset;
    STORAGE_OFFLOAD_TOKEN Token;
  } DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS, *PDEVICE_DSM_OFFLOAD_WRITE_PARAMETERS;

#define STORAGE_OFFLOAD_WRITE_RANGE_TRUNCATED 0x0001
#define STORAGE_OFFLOAD_TOKEN_INVALID         0x0002

  typedef struct _STORAGE_OFFLOAD_WRITE_OUTPUT
  {
    DWORD     OffloadWriteFlags;
    DWORD     Reserved;
    DWORDLONG LengthCopied;
  } STORAGE_OFFLOAD_WRITE_OUTPUT, *PSTORAGE_OFFLOAD_WRITE_OUTPUT;

#define DeviceDsmDefinition_OffloadWrite              \
  {                                                   \
    DeviceDsmAction_OffloadWrite,                     \
    FALSE,                                            \
    __alignof__(DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS), \
    sizeof(DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS),      \
    FALSE,                                            \
    __alignof__(STORAGE_OFFLOAD_WRITE_OUTPUT),        \
    sizeof(STORAGE_OFFLOAD_WRITE_OUTPUT)              \
  }

#define DEVICE_DSM_FLAG_ALLOCATION_CONSOLIDATEABLE_ONLY 0x40000000

  typedef struct _DEVICE_DATA_SET_LBP_STATE_PARAMETERS
  {
    DWORD Version;
    DWORD Size;
    DWORD Flags;
    DWORD OutputVersion;
  } DEVICE_DATA_SET_LBP_STATE_PARAMETERS, *PDEVICE_DATA_SET_LBP_STATE_PARAMETERS,
    DEVICE_DSM_ALLOCATION_PARAMETERS,     *PDEVICE_DSM_ALLOCATION_PARAMETERS;

#define DEVICE_DSM_PARAMETERS_V1                        1
#define DEVICE_DATA_SET_LBP_STATE_PARAMETERS_VERSION_V1 DEVICE_DSM_PARAMETERS_V1

  typedef struct _DEVICE_DATA_SET_LB_PROVISIONING_STATE
  {
    DWORD     Size;
    DWORD     Version;
    DWORDLONG SlabSizeInBytes;
    DWORD     SlabOffsetDeltaInBytes;
    DWORD     SlabAllocationBitMapBitCount;
    DWORD     SlabAllocationBitMapLength;
    DWORD     SlabAllocationBitMap[ANYSIZE_ARRAY];
  } DEVICE_DATA_SET_LB_PROVISIONING_STATE, *PDEVICE_DATA_SET_LB_PROVISIONING_STATE,
    DEVICE_DSM_ALLOCATION_OUTPUT,          *PDEVICE_DSM_ALLOCATION_OUTPUT;

#define DEVICE_DSM_ALLOCATION_OUTPUT_V1                  (sizeof(DEVICE_DSM_ALLOCATION_OUTPUT))
#define DEVICE_DATA_SET_LB_PROVISIONING_STATE_VERSION_V1 DEVICE_DSM_ALLOCATION_OUTPUT_V1

  typedef struct _DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2
  {
    DWORD     Size;
    DWORD     Version;
    DWORDLONG SlabSizeInBytes;
    DWORDLONG SlabOffsetDeltaInBytes;
    DWORD     SlabAllocationBitMapBitCount;
    DWORD     SlabAllocationBitMapLength;
    DWORD     SlabAllocationBitMap[ANYSIZE_ARRAY];
  } DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2, *PDEVICE_DATA_SET_LB_PROVISIONING_STATE_V2,
    DEVICE_DSM_ALLOCATION_OUTPUT2,            *PDEVICE_DSM_ALLOCATION_OUTPUT2;

#define DEVICE_DSM_ALLOCATION_OUTPUT_V2                  (sizeof(DEVICE_DSM_ALLOCATION_OUTPUT2))
#define DEVICE_DATA_SET_LB_PROVISIONING_STATE_VERSION_V2 DEVICE_DSM_ALLOCATION_OUTPUT_V2
#define DeviceDsmDefinition_Allocation             \
  {                                                \
    DeviceDsmAction_Allocation,                    \
    TRUE,                                          \
    __alignof__(DEVICE_DSM_ALLOCATION_PARAMETERS), \
    sizeof(DEVICE_DSM_ALLOCATION_PARAMETERS),      \
    TRUE,                                          \
    __alignof__(DEVICE_DSM_ALLOCATION_OUTPUT2),    \
    sizeof(DEVICE_DSM_ALLOCATION_OUTPUT2)          \
  }
#define DEVICE_DSM_FLAG_REPAIR_INPUT_TOPOLOGY_ID_PRESENT 0x40000000
#define DEVICE_DSM_FLAG_REPAIR_OUTPUT_PARITY_EXTENT      0x20000000
#define DEVICE_DSM_FLAG_SCRUB_SKIP_IN_SYNC               0x10000000
#define DEVICE_DSM_FLAG_SCRUB_OUTPUT_PARITY_EXTENT       0x20000000

  typedef struct _DEVICE_DATA_SET_REPAIR_PARAMETERS
  {
    DWORD NumberOfRepairCopies;
    DWORD SourceCopy;
    DWORD RepairCopies[ANYSIZE_ARRAY];
  } DEVICE_DATA_SET_REPAIR_PARAMETERS, *PDEVICE_DATA_SET_REPAIR_PARAMETERS,
    DEVICE_DSM_REPAIR_PARAMETERS,      *PDEVICE_DSM_REPAIR_PARAMETERS;

#define GET_REPAIR_TOPOLOGY_ID(R) \
  RtlOffsetToPointer(R, ALIGN_UP_BY(FIELD_OFFSET(DEVICE_DATA_SET_REPAIR_PARAMETERS, RepairCopies) + sizeof(DWORD) * R->NumberOfRepairCopies, 8))

  typedef struct _DEVICE_DATA_SET_REPAIR_OUTPUT
  {
    DEVICE_DSM_RANGE ParityExtent;
  } DEVICE_DATA_SET_REPAIR_OUTPUT, *PDEVICE_DATA_SET_REPAIR_OUTPUT,
    DEVICE_DSM_REPAIR_OUTPUT,      *PDEVICE_DSM_REPAIR_OUTPUT;

#define DeviceDsmDefinition_Repair             \
  {                                            \
    DeviceDsmAction_Repair,                    \
    TRUE,                                      \
    __alignof__(DEVICE_DSM_REPAIR_PARAMETERS), \
    sizeof(DEVICE_DSM_REPAIR_PARAMETERS),      \
    TRUE,                                      \
    __alignof__(DEVICE_DSM_REPAIR_OUTPUT),     \
    sizeof(DEVICE_DSM_REPAIR_OUTPUT)           \
  }

  typedef struct _DEVICE_DSM_QUERY_PREFER_LOCAL_REPAIR_OUTPUT
  {
    DWORD   Version;
    BOOLEAN PreferLocalRepair;
  } DEVICE_DSM_QUERY_PREFER_LOCAL_REPAIR_OUTPUT, *PDEVICE_DSM_QUERY_PREFER_LOCAL_REPAIR_OUTPUT;

#define DeviceDsmDefinition_QueryPreferLocalRepair            \
  {                                                           \
    DeviceDsmAction_QueryPreferLocalRepair,                   \
    FALSE,                                                    \
    0,                                                        \
    0,                                                        \
    TRUE,                                                     \
    __alignof__(DEVICE_DSM_QUERY_PREFER_LOCAL_REPAIR_OUTPUT), \
    sizeof(DEVICE_DSM_QUERY_PREFER_LOCAL_REPAIR_OUTPUT)       \
  }

  typedef struct _DEVICE_DATA_SET_SCRUB_OUTPUT
  {
    DWORDLONG BytesProcessed;
    DWORDLONG BytesRepaired;
    DWORDLONG BytesFailed;
  } DEVICE_DATA_SET_SCRUB_OUTPUT, *PDEVICE_DATA_SET_SCRUB_OUTPUT,
    DEVICE_DSM_SCRUB_OUTPUT,      *PDEVICE_DSM_SCRUB_OUTPUT;

  typedef struct _DEVICE_DATA_SET_SCRUB_EX_OUTPUT
  {
    DWORDLONG        BytesProcessed;
    DWORDLONG        BytesRepaired;
    DWORDLONG        BytesFailed;
    DEVICE_DSM_RANGE ParityExtent;
    DWORDLONG        BytesScrubbed;
  } DEVICE_DATA_SET_SCRUB_EX_OUTPUT, *PDEVICE_DATA_SET_SCRUB_EX_OUTPUT,
    DEVICE_DSM_SCRUB_OUTPUT2,        *PDEVICE_DSM_SCRUB_OUTPUT2;

#define DeviceDsmDefinition_Scrub          \
  {                                        \
    DeviceDsmAction_Scrub,                 \
    FALSE,                                 \
    0,                                     \
    0,                                     \
    TRUE,                                  \
    __alignof__(DEVICE_DSM_SCRUB_OUTPUT2), \
    sizeof(DEVICE_DSM_SCRUB_OUTPUT2)       \
  }

#define DeviceDsmDefinition_DrtQuery   {DeviceDsmAction_DrtQuery,   FALSE, 0, 0, TRUE,  0, 0}
#define DeviceDsmDefinition_DrtClear   {DeviceDsmAction_DrtClear,   FALSE, 0, 0, FALSE, 0, 0}
#define DeviceDsmDefinition_DrtDisable {DeviceDsmAction_DrtDisable, FALSE, 0, 0, FALSE, 0, 0}

  typedef struct _DEVICE_DSM_TIERING_QUERY_INPUT
  {
    DWORD Version;
    DWORD Size;
    DWORD Flags;
    DWORD NumberOfTierIds;
    GUID  TierIds[ANYSIZE_ARRAY];
  } DEVICE_DSM_TIERING_QUERY_INPUT,      *PDEVICE_DSM_TIERING_QUERY_INPUT,
    DEVICE_DSM_TIERING_QUERY_PARAMETERS, *PDEVICE_DSM_TIERING_QUERY_PARAMETERS;

  typedef struct _STORAGE_TIER_REGION
  {
    GUID      TierId;
    DWORDLONG Offset;
    DWORDLONG Length;
  } STORAGE_TIER_REGION, *PSTORAGE_TIER_REGION;

  typedef struct _DEVICE_DSM_TIERING_QUERY_OUTPUT
  {
    DWORD               Version;
    DWORD               Size;
    DWORD               Flags;
    DWORD               Reserved;
    DWORDLONG           Alignment;
    DWORD               TotalNumberOfRegions;
    DWORD               NumberOfRegionsReturned;
    STORAGE_TIER_REGION Regions[ANYSIZE_ARRAY];
  } DEVICE_DSM_TIERING_QUERY_OUTPUT, *PDEVICE_DSM_TIERING_QUERY_OUTPUT;

#define DeviceDsmDefinition_TieringQuery              \
  {                                                   \
    DeviceDsmAction_TieringQuery,                     \
    TRUE,                                             \
    __alignof__(DEVICE_DSM_TIERING_QUERY_PARAMETERS), \
    sizeof(DEVICE_DSM_TIERING_QUERY_PARAMETERS),      \
    TRUE,                                             \
    __alignof__(DEVICE_DSM_TIERING_QUERY_OUTPUT),     \
    sizeof(DEVICE_DSM_TIERING_QUERY_OUTPUT)           \
  }

#define DeviceDsmDefinition_Map              {DeviceDsmAction_Map,              FALSE, 0, 0, FALSE, 0, 0}
#define DeviceDsmDefinition_RegenerateParity {DeviceDsmAction_RegenerateParity, FALSE, 0, 0, FALSE, 0, 0}

  typedef struct _DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS
  {
    DWORD Size;
    BYTE  TargetPriority;
    BYTE  Reserved[3];
  } DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS, *PDEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS;

#define DeviceDsmDefinition_NvCache_Change_Priority             \
  {                                                             \
    DeviceDsmAction_NvCache_Change_Priority,                    \
    FALSE,                                                      \
    __alignof__(DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS), \
    sizeof(DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS),      \
    FALSE,                                                      \
    0,                                                          \
    0                                                           \
  }

#define DeviceDsmDefinition_NvCache_Evict {DeviceDsmAction_NvCache_Evict, FALSE, 0, 0, FALSE, 0, 0}

  typedef struct _DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT
  {
    DWORDLONG TopologyRangeBytes;
    BYTE      TopologyId[16];
  } DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT, *PDEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT,
    DEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT,      *PDEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT;

#define DeviceDsmDefinition_TopologyIdQuery           \
  {                                                   \
    DeviceDsmAction_TopologyIdQuery,                  \
    FALSE,                                            \
    0,                                                \
    0,                                                \
    TRUE,                                             \
    __alignof__(DEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT), \
    sizeof(DEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT)       \
  }

#define DEVICE_DSM_FLAG_PHYSICAL_ADDRESSES_OMIT_TOTAL_RANGES 0x10000000
#define DEVICE_DSM_PHYSICAL_ADDRESS_HAS_MEMORY_ERROR         ((LONGLONG)-1)

  typedef struct _DEVICE_STORAGE_ADDRESS_RANGE
  {
    LONGLONG  StartAddress;
    DWORDLONG LengthInBytes;
  } DEVICE_STORAGE_ADDRESS_RANGE, *PDEVICE_STORAGE_ADDRESS_RANGE;

  typedef struct _DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT
  {
    DWORD                        Version;
    DWORD                        Flags;
    DWORD                        TotalNumberOfRanges;
    DWORD                        NumberOfRangesReturned;
    DEVICE_STORAGE_ADDRESS_RANGE Ranges[ANYSIZE_ARRAY];
  } DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT, *PDEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT;

#define DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT_V1         1
#define DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT_VERSION_V1 DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT_V1

#define DeviceDsmDefinition_GetPhysicalAddresses       \
  {                                                    \
    DeviceDsmAction_GetPhysicalAddresses,              \
    FALSE,                                             \
    0,                                                 \
    0,                                                 \
    TRUE,                                              \
    __alignof__(DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT), \
    sizeof(DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT)       \
  }
#define DeviceDsmDefinition_ScopeRegen {DeviceDsmAction_ScopeRegen, FALSE, 0, 0, FALSE, 0, 0}

  typedef struct _DEVICE_DSM_REPORT_ZONES_PARAMETERS
  {
    DWORD Size;
    BYTE  ReportOption;
    BYTE  Partial;
    BYTE  Reserved[2];
  } DEVICE_DSM_REPORT_ZONES_PARAMETERS, *PDEVICE_DSM_REPORT_ZONES_PARAMETERS;

  typedef enum _STORAGE_ZONES_ATTRIBUTES
  {
    ZonesAttributeTypeAndLengthMayDifferent       = 0,
    ZonesAttributeTypeSameLengthSame              = 1,
    ZonesAttributeTypeSameLastZoneLengthDifferent = 2,
    ZonesAttributeTypeMayDifferentLengthSame      = 3,
  } STORAGE_ZONES_ATTRIBUTES, *PSTORAGE_ZONES_ATTRIBUTES;

  typedef enum _STORAGE_ZONE_CONDITION
  {
    ZoneConditionConventional     = 0x00,
    ZoneConditionEmpty            = 0x01,
    ZoneConditionImplicitlyOpened = 0x02,
    ZoneConditionExplicitlyOpened = 0x03,
    ZoneConditionClosed           = 0x04,
    ZoneConditionReadOnly         = 0x0D,
    ZoneConditionFull             = 0x0E,
    ZoneConditionOffline          = 0x0F,
  } STORAGE_ZONE_CONDITION, *PSTORAGE_ZONE_CONDITION;

  typedef struct _STORAGE_ZONE_DESCRIPTOR
  {
    DWORD                  Size;
    STORAGE_ZONE_TYPES     ZoneType;
    STORAGE_ZONE_CONDITION ZoneCondition;
    BOOLEAN                ResetWritePointerRecommend;
    BYTE                   Reserved0[3];
    DWORDLONG              ZoneSize;
    DWORDLONG              WritePointerOffset;
  } STORAGE_ZONE_DESCRIPTOR, *PSTORAGE_ZONE_DESCRIPTOR;

  typedef struct _DEVICE_DSM_REPORT_ZONES_DATA
  {
    DWORD                    Size;
    DWORD                    ZoneCount;
    STORAGE_ZONES_ATTRIBUTES Attributes;
    DWORD                    Reserved0;
    STORAGE_ZONE_DESCRIPTOR  ZoneDescriptors[ANYSIZE_ARRAY];
  } DEVICE_DSM_REPORT_ZONES_DATA,   *PDEVICE_DSM_REPORT_ZONES_DATA,
    DEVICE_DSM_REPORT_ZONES_OUTPUT, *PDEVICE_DSM_REPORT_ZONES_OUTPUT;

#define DeviceDsmDefinition_ReportZones              \
  {                                                  \
    DeviceDsmAction_ReportZones,                     \
    FALSE,                                           \
    __alignof__(DEVICE_DSM_REPORT_ZONES_PARAMETERS), \
    sizeof(DEVICE_DSM_REPORT_ZONES_PARAMETERS),      \
    TRUE,                                            \
    __alignof__(DEVICE_DSM_REPORT_ZONES_OUTPUT),     \
    sizeof(DEVICE_DSM_REPORT_ZONES_OUTPUT)           \
  }

#define DeviceDsmDefinition_OpenZone          {DeviceDsmAction_OpenZone,          FALSE, 0, 0, FALSE, 0, 0}
#define DeviceDsmDefinition_FinishZone        {DeviceDsmAction_FinishZone,        FALSE, 0, 0, FALSE, 0, 0}
#define DeviceDsmDefinition_CloseZone         {DeviceDsmAction_CloseZone,         FALSE, 0, 0, FALSE, 0, 0}
#define DeviceDsmDefinition_ResetWritePointer {DeviceDsmAction_ResetWritePointer, FALSE, 0, 0, FALSE, 0, 0}

  typedef struct _DEVICE_STORAGE_RANGE_ATTRIBUTES
  {
    DWORDLONG LengthInBytes;
    __C89_NAMELESS union
    {
      DWORD AllFlags;
      __C89_NAMELESS struct
      {
        DWORD IsRangeBad : 1;
      } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    DWORD Reserved;
  } DEVICE_STORAGE_RANGE_ATTRIBUTES, *PDEVICE_STORAGE_RANGE_ATTRIBUTES;

#define DEVICE_STORAGE_NO_ERRORS 0x1

  typedef struct _DEVICE_DSM_RANGE_ERROR_INFO
  {
    DWORD                           Version;
    DWORD                           Flags;
    DWORD                           TotalNumberOfRanges;
    DWORD                           NumberOfRangesReturned;
    DEVICE_STORAGE_RANGE_ATTRIBUTES Ranges[ANYSIZE_ARRAY];
  } DEVICE_DSM_RANGE_ERROR_INFO,   *PDEVICE_DSM_RANGE_ERROR_INFO,
    DEVICE_DSM_RANGE_ERROR_OUTPUT, *PDEVICE_DSM_RANGE_ERROR_OUTPUT;

#define DEVICE_DSM_RANGE_ERROR_OUTPUT_V1       1
#define DEVICE_DSM_RANGE_ERROR_INFO_VERSION_V1 DEVICE_DSM_RANGE_ERROR_OUTPUT_V1

#define DeviceDsmDefinition_GetRangeErrorInfo   \
  {                                             \
    DeviceDsmAction_GetRangeErrorInfo,          \
    FALSE,                                      \
    0,                                          \
    0,                                          \
    TRUE,                                       \
    __alignof__(DEVICE_DSM_RANGE_ERROR_OUTPUT), \
    sizeof(DEVICE_DSM_RANGE_ERROR_OUTPUT)       \
  }
#define DeviceDsmDefinition_WriteZeroes {DeviceDsmAction_WriteZeroes, FALSE, 0, 0, FALSE, 0, 0}

  typedef struct _DEVICE_DSM_LOST_QUERY_PARAMETERS
  {
    DWORD     Version;
    DWORDLONG Granularity;
  } DEVICE_DSM_LOST_QUERY_PARAMETERS, *PDEVICE_DSM_LOST_QUERY_PARAMETERS;

  typedef struct _DEVICE_DSM_LOST_QUERY_OUTPUT
  {
    DWORD     Version;
    DWORD     Size;
    DWORDLONG Alignment;
    DWORD     NumberOfBits;
    DWORD     BitMap[ANYSIZE_ARRAY];
  } DEVICE_DSM_LOST_QUERY_OUTPUT, *PDEVICE_DSM_LOST_QUERY_OUTPUT;

#define DeviceDsmDefinition_LostQuery              \
  {                                                \
    DeviceDsmAction_LostQuery,                     \
    TRUE,                                          \
    __alignof__(DEVICE_DSM_LOST_QUERY_PARAMETERS), \
    sizeof(DEVICE_DSM_LOST_QUERY_PARAMETERS),      \
    TRUE,                                          \
    __alignof__(DEVICE_DSM_LOST_QUERY_OUTPUT),     \
    sizeof(DEVICE_DSM_LOST_QUERY_OUTPUT)           \
  }

  typedef struct _DEVICE_DSM_FREE_SPACE_OUTPUT
  {
    DWORD     Version;
    DWORDLONG FreeSpace;
  } DEVICE_DSM_FREE_SPACE_OUTPUT, *PDEVICE_DSM_FREE_SPACE_OUTPUT;

#define DeviceDsmDefinition_GetFreeSpace       \
  {                                            \
    DeviceDsmAction_GetFreeSpace,              \
    FALSE,                                     \
    0,                                         \
    0,                                         \
    TRUE,                                      \
    __alignof__(DEVICE_DSM_FREE_SPACE_OUTPUT), \
    sizeof(DEVICE_DSM_FREE_SPACE_OUTPUT)       \
  }

  typedef struct _DEVICE_DSM_CONVERSION_OUTPUT
  {
    DWORD Version;
    GUID  Source;
  } DEVICE_DSM_CONVERSION_OUTPUT, *PDEVICE_DSM_CONVERSION_OUTPUT;

#define DeviceDsmDefinition_ConversionQuery    \
  {                                            \
    DeviceDsmAction_ConversionQuery,           \
    TRUE,                                      \
    0,                                         \
    0,                                         \
    TRUE,                                      \
    __alignof__(DEVICE_DSM_CONVERSION_OUTPUT), \
    sizeof(DEVICE_DSM_CONVERSION_OUTPUT)       \
  }
#define DeviceDsmDefinition_VdtSet {DeviceDsmAction_VdtSet, FALSE, 0, 0, FALSE, 0, 0}

#define DEVICE_DSM_ROUND_UP(_a, _b) (((_a) + ((_b) - 1)) / (_b) * (_b))
#define DEVICE_DSM_ROUND_DN(_a, _b) (((_a)             ) / (_b) * (_b))

  FORCEINLINE
  PVOID DeviceDsmParameterBlock(PDEVICE_DSM_INPUT Input)
  {
    return (PVOID)((DWORD_PTR)Input + Input->ParameterBlockOffset);
  }

  FORCEINLINE
  PDEVICE_DSM_RANGE DeviceDsmDataSetRanges(PDEVICE_DSM_INPUT Input)
  {
    return (PDEVICE_DSM_RANGE)((DWORD_PTR)Input + Input->DataSetRangesOffset);
  }

  FORCEINLINE
  DWORD DeviceDsmNumberOfDataSetRanges(PDEVICE_DSM_INPUT Input)
  {
    return Input->DataSetRangesLength / sizeof(DEVICE_DSM_RANGE);
  }

  FORCEINLINE
  DWORD DeviceDsmGetInputLength(PDEVICE_DSM_DEFINITION Definition, DWORD ParameterBlockLength, DWORD NumberOfDataSetRanges)
  {
    DWORD Bytes = sizeof(DEVICE_DSM_INPUT);
    if(ParameterBlockLength != 0)
    {
      Bytes  = DEVICE_DSM_ROUND_UP(Bytes, Definition->ParameterBlockAlignment);
      Bytes += ParameterBlockLength;
    }

    if(NumberOfDataSetRanges != 0)
    {
      Bytes  = DEVICE_DSM_ROUND_UP(Bytes, __alignof__(DEVICE_DSM_RANGE));
      Bytes += sizeof(DEVICE_DSM_RANGE) * NumberOfDataSetRanges;
    }

    return Bytes;
  }

  FORCEINLINE
  DWORD DeviceDsmGetNumberOfDataSetRanges(PDEVICE_DSM_DEFINITION Definition, DWORD InputLength, DWORD ParameterBlockLength)
  {
    DWORD Bytes = sizeof(DEVICE_DSM_INPUT);
    if(ParameterBlockLength != 0)
    {
      Bytes  = DEVICE_DSM_ROUND_UP(Bytes, Definition->ParameterBlockAlignment);
      Bytes += ParameterBlockLength;
    }

    Bytes = DEVICE_DSM_ROUND_UP(Bytes, __alignof__(DEVICE_DSM_RANGE));
    Bytes = InputLength - Bytes;

    return Bytes / sizeof(DEVICE_DSM_RANGE);
  }

  FORCEINLINE
  VOID DeviceDsmInitializeInput(PDEVICE_DSM_DEFINITION Definition, PDEVICE_DSM_INPUT Input, DWORD InputLength, DWORD Flags, PVOID Parameters, DWORD ParameterBlockLength)
  {
    DWORD Bytes = sizeof(DEVICE_DSM_INPUT);
    RtlZeroMemory(Input, InputLength);
    Input->Size   = Bytes;
    Input->Action = Definition->Action;
    Input->Flags  = Flags;
    if(ParameterBlockLength == 0)
    {
      goto Cleanup;
    }

    Bytes                       = DEVICE_DSM_ROUND_UP(Bytes, Definition->ParameterBlockAlignment);
    Input->ParameterBlockOffset = Bytes;
    Input->ParameterBlockLength = ParameterBlockLength;

    if(!Parameters)
    {
      goto Cleanup;
    }

    RtlCopyMemory(DeviceDsmParameterBlock(Input), Parameters, Input->ParameterBlockLength);

Cleanup:
    return;
  }

  FORCEINLINE
  BOOLEAN DeviceDsmAddDataSetRange(PDEVICE_DSM_INPUT Input, DWORD InputLength, LONGLONG Offset, DWORDLONG Length)
  {
    DWORD             Bytes  = 0;
    DWORD             Index  = 0;
    PDEVICE_DSM_RANGE Ranges = NULL;
    BOOLEAN           Return = FALSE;
    if(Input->Flags & DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE)
    {
      goto Cleanup;
    }

    if(Input->DataSetRangesLength == 0)
    {
      if(Input->ParameterBlockLength == 0)
      {
        Bytes = sizeof(DEVICE_DSM_INPUT);
      }
      else
      {
        Bytes = Input->ParameterBlockOffset + Input->ParameterBlockLength;
      }
      Bytes = DEVICE_DSM_ROUND_UP(Bytes, __alignof__(DEVICE_DSM_RANGE));
    }
    else
    {
      Bytes = Input->DataSetRangesOffset + Input->DataSetRangesLength;
    }

    if((InputLength - Bytes) < sizeof(DEVICE_DSM_RANGE))
    {
      goto Cleanup;
    }

    if(Input->DataSetRangesOffset == 0)
    {
      Input->DataSetRangesOffset  = Bytes;
    }

    Ranges                       = DeviceDsmDataSetRanges(Input);
    Index                        = DeviceDsmNumberOfDataSetRanges(Input);
    Ranges[Index].StartingOffset = Offset;
    Ranges[Index].LengthInBytes  = Length;
    Input->DataSetRangesLength  += sizeof(DEVICE_DSM_RANGE);
    Return                       = TRUE;

Cleanup:
    return Return;
  }

  FORCEINLINE
  BOOLEAN DeviceDsmValidateInput(PDEVICE_DSM_DEFINITION Definition, PDEVICE_DSM_INPUT Input, DWORD InputLength)
  {
    DWORD   Max   = 0;
    DWORD   Min   = 0;
    BOOLEAN Valid = FALSE;
    if(Definition->Action != Input->Action)
    {
      goto Cleanup;
    }

    if(Definition->ParameterBlockLength != 0)
    {
        Min = sizeof(*Input);
        Max = InputLength;
        if(Input->ParameterBlockOffset < Min || Input->ParameterBlockOffset > Max || Input->ParameterBlockOffset % Definition->ParameterBlockAlignment)
        {
          goto Cleanup;
        }

        Min = Definition->ParameterBlockLength;
        Max = InputLength - Input->ParameterBlockOffset;
        if(Input->ParameterBlockLength < Min || Input->ParameterBlockLength > Max)
        {
          goto Cleanup;
        }
    }

    if(!(Input->Flags & DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE))
    {
      Min = sizeof(*Input);
      Max = InputLength;
      if(Input->DataSetRangesOffset < Min || Input->DataSetRangesOffset > Max || Input->DataSetRangesOffset % __alignof__(DEVICE_DSM_RANGE))
      {
        goto Cleanup;
      }

      Min = sizeof(DEVICE_DSM_RANGE);
      Max = InputLength - Input->DataSetRangesOffset;
      if(Input->DataSetRangesLength < Min || Input->DataSetRangesLength > Max || Input->DataSetRangesLength % Min)
      {
        goto Cleanup;
      }

      if(Definition->SingleRange && Input->DataSetRangesLength != Min)
      {
        goto Cleanup;
      }
    }
    else
    {
      if(Input->DataSetRangesOffset != 0 || Input->DataSetRangesLength != 0)
      {
        goto Cleanup;
      }
    }

    if(Input->ParameterBlockOffset < Input->DataSetRangesOffset && Input->ParameterBlockOffset + Input->ParameterBlockLength > Input->DataSetRangesOffset)
    {
      goto Cleanup;
    }

    if(Input->DataSetRangesOffset < Input->ParameterBlockOffset && Input->DataSetRangesOffset + Input->DataSetRangesLength > Input->ParameterBlockOffset)
    {
      goto Cleanup;
    }

    Valid = TRUE;

Cleanup:
    return Valid;
  }

  FORCEINLINE
  PVOID DeviceDsmOutputBlock(PDEVICE_DSM_OUTPUT Output)
  {
    return (PVOID)((DWORD_PTR)Output + Output->OutputBlockOffset);
  }

  FORCEINLINE
  DWORD DeviceDsmGetOutputLength(PDEVICE_DSM_DEFINITION Definition, DWORD OutputBlockLength)
  {
    DWORD Bytes = 0;
    if(!Definition->HasOutput)
    {
      goto Cleanup;
    }

    Bytes = sizeof(DEVICE_DSM_OUTPUT);
    if(Definition->OutputBlockLength == 0)
    {
      goto Cleanup;
    }

    if(Definition->OutputBlockLength > OutputBlockLength)
    {
      OutputBlockLength = Definition->OutputBlockLength;
    }

    Bytes  = DEVICE_DSM_ROUND_UP(Bytes, Definition->OutputBlockAlignment);
    Bytes += OutputBlockLength;

Cleanup:
    return Bytes;
  }

  FORCEINLINE
  BOOLEAN DeviceDsmValidateOutputLength(PDEVICE_DSM_DEFINITION Definition, DWORD OutputLength)
  {
    DWORD Bytes = DeviceDsmGetOutputLength(Definition, 0);
    return (OutputLength >= Bytes);
  }

  FORCEINLINE
  DWORD DeviceDsmGetOutputBlockLength(PDEVICE_DSM_DEFINITION Definition, DWORD OutputLength)
  {
    DWORD Bytes = 0;
    if(Definition->OutputBlockLength == 0)
    {
      goto Cleanup;
    }

    Bytes = sizeof(DEVICE_DSM_OUTPUT);
    Bytes = DEVICE_DSM_ROUND_UP(Bytes, Definition->OutputBlockAlignment);
    Bytes = OutputLength - Bytes;

Cleanup:
    return Bytes;
  }

  FORCEINLINE
  VOID DeviceDsmInitializeOutput(PDEVICE_DSM_DEFINITION Definition, PDEVICE_DSM_OUTPUT Output, DWORD OutputLength, DWORD Flags)
  {
    DWORD Bytes = sizeof(DEVICE_DSM_OUTPUT);
    RtlZeroMemory(Output, OutputLength);
    Output->Size   = Bytes;
    Output->Action = Definition->Action;
    Output->Flags  = Flags;
    if(Definition->OutputBlockLength != 0)
    {
      Bytes = DEVICE_DSM_ROUND_UP(Bytes, Definition->OutputBlockAlignment);
      Output->OutputBlockOffset = Bytes;
      Output->OutputBlockLength = OutputLength - Bytes;
    }

    return;
  }

  FORCEINLINE
  BOOLEAN DeviceDsmValidateOutput(PDEVICE_DSM_DEFINITION Definition, PDEVICE_DSM_OUTPUT Output, DWORD OutputLength)
  {
    DWORD   Max   = 0;
    DWORD   Min   = 0;
    BOOLEAN Valid = FALSE;
    if(Definition->Action != Output->Action)
    {
      goto Cleanup;
    }

    if(!Definition->HasOutput)
    {
      goto Cleanup;
    }

    if(Definition->OutputBlockLength != 0)
    {
      Min = sizeof(*Output);
      Max = OutputLength;
      if(Output->OutputBlockOffset < Min || Output->OutputBlockOffset > Max || Output->OutputBlockOffset % Definition->OutputBlockAlignment)
      {
        goto Cleanup;
      }

      Min = Definition->OutputBlockLength;
      Max = OutputLength - Output->OutputBlockOffset;
      if(Output->OutputBlockLength < Min || Output->OutputBlockLength > Max)
      {
        goto Cleanup;
      }
    }
    else
    {
      if(Output->OutputBlockOffset != 0 || Output->OutputBlockLength != 0)
      {
        goto Cleanup;
      }
    }
    Valid = TRUE;

Cleanup:
    return Valid;
  }

  typedef struct _STORAGE_GET_BC_PROPERTIES_OUTPUT
  {
    DWORD     MaximumRequestsPerPeriod;
    DWORD     MinimumPeriod;
    DWORDLONG MaximumRequestSize;
    DWORD     EstimatedTimePerRequest;
    DWORD     NumOutStandingRequests;
    DWORDLONG RequestSize;
  } STORAGE_GET_BC_PROPERTIES_OUTPUT, *PSTORAGE_GET_BC_PROPERTIES_OUTPUT;

#define IOCTL_STORAGE_BC_VERSION 1

  typedef struct _STORAGE_ALLOCATE_BC_STREAM_INPUT
  {
    DWORD   Version;
    DWORD   RequestsPerPeriod;
    DWORD   Period;
    BOOLEAN RetryFailures;
    BOOLEAN Discardable;
    BOOLEAN Reserved1[2];
    DWORD   AccessType;
    DWORD   AccessMode;
  } STORAGE_ALLOCATE_BC_STREAM_INPUT, *PSTORAGE_ALLOCATE_BC_STREAM_INPUT;

  typedef struct _STORAGE_ALLOCATE_BC_STREAM_OUTPUT
  {
    DWORDLONG RequestSize;
    DWORD     NumOutStandingRequests;
  } STORAGE_ALLOCATE_BC_STREAM_OUTPUT, *PSTORAGE_ALLOCATE_BC_STREAM_OUTPUT;

#define STORAGE_PRIORITY_HINT_SUPPORTED 0x0001

  typedef struct _STORAGE_PRIORITY_HINT_SUPPORT
  {
    DWORD SupportFlags;
  } STORAGE_PRIORITY_HINT_SUPPORT, *PSTORAGE_PRIORITY_HINT_SUPPORT;

  typedef enum _STORAGE_DIAGNOSTIC_LEVEL
  {
    StorageDiagnosticLevelDefault = 0,
    StorageDiagnosticLevelMax
  } STORAGE_DIAGNOSTIC_LEVEL, *PSTORAGE_DIAGNOSTIC_LEVEL;

  typedef enum _STORAGE_DIAGNOSTIC_TARGET_TYPE
  {
    StorageDiagnosticTargetTypeUndefined = 0,
    StorageDiagnosticTargetTypePort,
    StorageDiagnosticTargetTypeMiniport,
    StorageDiagnosticTargetTypeHbaFirmware,
    StorageDiagnosticTargetTypeMax
  } STORAGE_DIAGNOSTIC_TARGET_TYPE, *PSTORAGE_DIAGNOSTIC_TARGET_TYPE;

#define STORAGE_DIAGNOSTIC_FLAG_ADAPTER_REQUEST 0x00000001

  typedef struct _STORAGE_DIAGNOSTIC_REQUEST
  {
    DWORD                          Version;
    DWORD                          Size;
    DWORD                          Flags;
    STORAGE_DIAGNOSTIC_TARGET_TYPE TargetType;
    STORAGE_DIAGNOSTIC_LEVEL       Level;
  } STORAGE_DIAGNOSTIC_REQUEST, *PSTORAGE_DIAGNOSTIC_REQUEST;

  typedef struct _STORAGE_DIAGNOSTIC_DATA
  {
    DWORD Version;
    DWORD Size;
    GUID  ProviderId;
    DWORD BufferSize;
    DWORD Reserved;
    BYTE  DiagnosticDataBuffer[ANYSIZE_ARRAY];
  } STORAGE_DIAGNOSTIC_DATA, *PSTORAGE_DIAGNOSTIC_DATA;

  typedef struct _PHYSICAL_ELEMENT_STATUS_REQUEST
  {
    DWORD Version;
    DWORD Size;
    DWORD StartingElement;
    BYTE  Filter;
    BYTE  ReportType;
    BYTE  Reserved[2];
  } PHYSICAL_ELEMENT_STATUS_REQUEST, *PPHYSICAL_ELEMENT_STATUS_REQUEST;

  typedef struct _PHYSICAL_ELEMENT_STATUS_DESCRIPTOR
  {
    DWORD     Version;
    DWORD     Size;
    DWORD     ElementIdentifier;
    BYTE      PhysicalElementType;
    BYTE      PhysicalElementHealth;
    BYTE      Reserved1[2];
    DWORDLONG AssociatedCapacity;
    DWORD     Reserved2[4];
  } PHYSICAL_ELEMENT_STATUS_DESCRIPTOR, *PPHYSICAL_ELEMENT_STATUS_DESCRIPTOR;

  typedef struct _PHYSICAL_ELEMENT_STATUS
  {
    DWORD                              Version;
    DWORD                              Size;
    DWORD                              DescriptorCount;
    DWORD                              ReturnedDescriptorCount;
    DWORD                              ElementIdentifierBeingDepoped;
    DWORD                              Reserved;
    PHYSICAL_ELEMENT_STATUS_DESCRIPTOR Descriptors[ANYSIZE_ARRAY];
  } PHYSICAL_ELEMENT_STATUS, *PPHYSICAL_ELEMENT_STATUS;

  typedef struct _REMOVE_ELEMENT_AND_TRUNCATE_REQUEST
  {
    DWORD     Version;
    DWORD     Size;
    DWORDLONG RequestCapacity;
    DWORD     ElementIdentifier;
    DWORD     Reserved;
  } REMOVE_ELEMENT_AND_TRUNCATE_REQUEST, *PREMOVE_ELEMENT_AND_TRUNCATE_REQUEST;

#define ERROR_HISTORY_DIRECTORY_ENTRY_DEFAULT_COUNT 8

  typedef enum _DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE
  {
    DeviceInternalStatusDataRequestTypeUndefined = 0,
    DeviceCurrentInternalStatusDataHeader,
    DeviceCurrentInternalStatusData,
    DeviceSavedInternalStatusDataHeader,
    DeviceSavedInternalStatusData
  } DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE, *PDEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE;

  typedef enum _DEVICE_INTERNAL_STATUS_DATA_SET
  {
    DeviceStatusDataSetUndefined = 0,
    DeviceStatusDataSet1,
    DeviceStatusDataSet2,
    DeviceStatusDataSet3,
    DeviceStatusDataSet4,
    DeviceStatusDataSetMax
  } DEVICE_INTERNAL_STATUS_DATA_SET, *PDEVICE_INTERNAL_STATUS_DATA_SET;

  typedef struct _GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST
  {
    DWORD                                    Version;
    DWORD                                    Size;
    DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE RequestDataType;
    DEVICE_INTERNAL_STATUS_DATA_SET          RequestDataSet;
  } GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST, *PGET_DEVICE_INTERNAL_STATUS_DATA_REQUEST;

  typedef struct _DEVICE_INTERNAL_STATUS_DATA
  {
    DWORD     Version;
    DWORD     Size;
    DWORDLONG T10VendorId;
    DWORD     DataSet1Length;
    DWORD     DataSet2Length;
    DWORD     DataSet3Length;
    DWORD     DataSet4Length;
    BYTE      StatusDataVersion;
    BYTE      Reserved[3];
    BYTE      ReasonIdentifier[128];
    DWORD     StatusDataLength;
    BYTE      StatusData[ANYSIZE_ARRAY];
  } DEVICE_INTERNAL_STATUS_DATA, *PDEVICE_INTERNAL_STATUS_DATA;

  typedef enum _STORAGE_SANITIZE_METHOD
  {
    StorageSanitizeMethodDefault = 0,
    StorageSanitizeMethodBlockErase,
    StorageSanitizeMethodCryptoErase
  } STORAGE_SANITIZE_METHOD, *PSTORAGE_SANITIZE_METHOD;

  typedef struct _STORAGE_REINITIALIZE_MEDIA
  {
    DWORD Version;
    DWORD Size;
    DWORD TimeoutInSeconds;
    struct
    {
      DWORD SanitizeMethod                   : 4;
      DWORD DisallowUnrestrictedSanitizeExit : 1;
      DWORD Reserved                         : 27;
    } SanitizeOption;
  } STORAGE_REINITIALIZE_MEDIA, *PSTORAGE_REINITIALIZE_MEDIA;

  typedef struct _STORAGE_MEDIA_SERIAL_NUMBER_DATA
  {
    WORD Reserved;
    WORD SerialNumberLength;
#ifndef __WIDL__
    BYTE SerialNumber[0];
#endif
  } STORAGE_MEDIA_SERIAL_NUMBER_DATA, *PSTORAGE_MEDIA_SERIAL_NUMBER_DATA;

  typedef struct _STORAGE_READ_CAPACITY
  {
    DWORD         Version;
    DWORD         Size;
    DWORD         BlockLength;
    LARGE_INTEGER NumberOfBlocks;
    LARGE_INTEGER DiskLength;
  } STORAGE_READ_CAPACITY, *PSTORAGE_READ_CAPACITY;

  typedef enum _WRITE_CACHE_TYPE
  {
    WriteCacheTypeUnknown,
    WriteCacheTypeNone,
    WriteCacheTypeWriteBack,
    WriteCacheTypeWriteThrough
  } WRITE_CACHE_TYPE;

  typedef enum _WRITE_CACHE_ENABLE
  {
    WriteCacheEnableUnknown,
    WriteCacheDisabled,
    WriteCacheEnabled
  } WRITE_CACHE_ENABLE;

  typedef enum _WRITE_CACHE_CHANGE
  {
    WriteCacheChangeUnknown,
    WriteCacheNotChangeable,
    WriteCacheChangeable
  } WRITE_CACHE_CHANGE;

  typedef enum _WRITE_THROUGH
  {
    WriteThroughUnknown,
    WriteThroughNotSupported,
    WriteThroughSupported
  } WRITE_THROUGH;

  typedef struct _STORAGE_WRITE_CACHE_PROPERTY
  {
    DWORD              Version;
    DWORD              Size;
    WRITE_CACHE_TYPE   WriteCacheType;
    WRITE_CACHE_ENABLE WriteCacheEnabled;
    WRITE_CACHE_CHANGE WriteCacheChangeable;
    WRITE_THROUGH      WriteThroughSupported;
    BOOLEAN            FlushCacheSupported;
    BOOLEAN            UserDefinedPowerProtection;
    BOOLEAN            NVCacheEnabled;
  } STORAGE_WRITE_CACHE_PROPERTY, *PSTORAGE_WRITE_CACHE_PROPERTY;

  typedef struct _PERSISTENT_RESERVE_COMMAND
  {
    DWORD Version;
    DWORD Size;
    __C89_NAMELESS union
    {
      struct
      {
        BYTE  ServiceAction : 5;
        BYTE  Reserved1     : 3;
        DWORD AllocationLength;
      } PR_IN;
      struct
      {
        BYTE ServiceAction : 5;
        BYTE Reserved1     : 3;
        BYTE Type          : 4;
        BYTE Scope         : 4;
#ifndef __WIDL__
        BYTE ParameterList[0];
#endif
      } PR_OUT;
    } DUMMYUNIONNAME;
  } PERSISTENT_RESERVE_COMMAND, *PPERSISTENT_RESERVE_COMMAND;

#define DEVICEDUMP_STRUCTURE_VERSION_V1 1
#define DEVICEDUMP_MAX_IDSTRING         32
#define MAX_FW_BUCKET_ID_LENGTH         132

#define STORAGE_CRASH_TELEMETRY_REGKEY  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\StorageTelemetry"
#define STORAGE_DEVICE_TELEMETRY_REGKEY L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Storage\\StorageTelemetry"

  typedef enum _DEVICEDUMP_COLLECTION_TYPE
  {
    TCCollectionBugCheck = 1,
    TCCollectionApplicationRequested,
    TCCollectionDeviceRequested
  } DEVICEDUMP_COLLECTION_TYPEIDE_NOTIFICATION_TYPE, *PDEVICEDUMP_COLLECTION_TYPE;

#define DDUMP_FLAG_DATA_READ_FROM_DEVICE 0x0001

#define FW_ISSUEID_NO_ISSUE 0x00000000
#define FW_ISSUEID_UNKNOWN  0xFFFFFFFF

#include <pshpack1.h>

  typedef struct _DEVICEDUMP_SUBSECTION_POINTER
  {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwOffset;
  } DEVICEDUMP_SUBSECTION_POINTER, *PDEVICEDUMP_SUBSECTION_POINTER;

  typedef struct _DEVICEDUMP_STRUCTURE_VERSION
  {
    DWORD dwSignature;
    DWORD dwVersion;
    DWORD dwSize;
  } DEVICEDUMP_STRUCTURE_VERSION, *PDEVICEDUMP_STRUCTURE_VERSION;

  typedef  struct _DEVICEDUMP_SECTION_HEADER
  {
    GUID  guidDeviceDataId;
    BYTE  sOrganizationID[16];
    DWORD dwFirmwareRevision;
    BYTE  sModelNumber[DEVICEDUMP_MAX_IDSTRING];
    BYTE  szDeviceManufacturingID[DEVICEDUMP_MAX_IDSTRING];
    DWORD dwFlags;
    DWORD bRestrictedPrivateDataVersion;
    DWORD dwFirmwareIssueId;
    BYTE  szIssueDescriptionString[MAX_FW_BUCKET_ID_LENGTH];
  } DEVICEDUMP_SECTION_HEADER, *PDEVICEDUMP_SECTION_HEADER;

#define TC_PUBLIC_DEVICEDUMP_CONTENT_SMART     0x01
#define TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG     0x02
#define TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG_MAX 16
#define TC_DEVICEDUMP_SUBSECTION_DESC_LENGTH   16
#define TC_PUBLIC_DATA_TYPE_ATAGP              "ATAGPLogPages"
#define TC_PUBLIC_DATA_TYPE_ATASMART           "ATASMARTPages"

  typedef struct _GP_LOG_PAGE_DESCRIPTOR
  {
    WORD LogAddress;
    WORD LogSectors;
  } GP_LOG_PAGE_DESCRIPTOR, *PGP_LOG_PAGE_DESCRIPTOR;

  typedef struct _DEVICEDUMP_PUBLIC_SUBSECTION
  {
    DWORD                  dwFlags;
    GP_LOG_PAGE_DESCRIPTOR GPLogTable[TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG_MAX];
    CHAR                   szDescription[TC_DEVICEDUMP_SUBSECTION_DESC_LENGTH];
    BYTE                   bData[ANYSIZE_ARRAY];
  } DEVICEDUMP_PUBLIC_SUBSECTION, *PDEVICEDUMP_PUBLIC_SUBSECTION;

  typedef struct _DEVICEDUMP_RESTRICTED_SUBSECTION
  {
    BYTE bData[ANYSIZE_ARRAY];
  } DEVICEDUMP_RESTRICTED_SUBSECTION, *PDEVICEDUMP_RESTRICTED_SUBSECTION;

  typedef struct _DEVICEDUMP_PRIVATE_SUBSECTION
  {
    DWORD                  dwFlags;
    GP_LOG_PAGE_DESCRIPTOR GPLogId;
    BYTE                   bData[ANYSIZE_ARRAY];
  } DEVICEDUMP_PRIVATE_SUBSECTION, *PDEVICEDUMP_PRIVATE_SUBSECTION;

  typedef struct _DEVICEDUMP_STORAGEDEVICE_DATA
  {
    DEVICEDUMP_STRUCTURE_VERSION  Descriptor;
    DEVICEDUMP_SECTION_HEADER     SectionHeader;
    DWORD                         dwBufferSize;
    DWORD                         dwReasonForCollection;
    DEVICEDUMP_SUBSECTION_POINTER PublicData;
    DEVICEDUMP_SUBSECTION_POINTER RestrictedData;
    DEVICEDUMP_SUBSECTION_POINTER PrivateData;
  } DEVICEDUMP_STORAGEDEVICE_DATA, *PDEVICEDUMP_STORAGEDEVICE_DATA;

#define CDB_SIZE                    16
#define TELEMETRY_COMMAND_SIZE      16
#define TCRecordStorportSrbFunction Command[0]

  typedef struct _DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD
  {
    BYTE      Cdb[CDB_SIZE];
    BYTE      Command[TELEMETRY_COMMAND_SIZE];
    DWORDLONG StartTime;
    DWORDLONG EndTime;
    DWORD     OperationStatus;
    DWORD     OperationError;
    union
    {
      struct
      {
        DWORD dwReserved;
      } ExternalStack;
      struct
      {
        DWORD dwAtaPortSpecific;
      } AtaPort;
      struct
      {
        DWORD SrbTag;
      } StorPort;
    } StackSpecific;
  } DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD, *PDEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD;

  typedef struct _DEVICEDUMP_STORAGESTACK_PUBLIC_DUMP
  {
    DEVICEDUMP_STRUCTURE_VERSION                Descriptor;
    DWORD                                       dwReasonForCollection;
    BYTE                                        cDriverName[16];
    DWORD                                       uiNumRecords;
    DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD RecordArray[ANYSIZE_ARRAY];
  } DEVICEDUMP_STORAGESTACK_PUBLIC_DUMP, *PDEVICEDUMP_STORAGESTACK_PUBLIC_DUMP;

#include <poppack.h>

#define DEVICEDUMP_CAP_PRIVATE_SECTION    0x00000001
#define DEVICEDUMP_CAP_RESTRICTED_SECTION 0x00000002

  typedef struct _STORAGE_IDLE_POWER
  {
    DWORD Version;
    DWORD Size;
    DWORD WakeCapableHint : 1;
    DWORD D3ColdSupported : 1;
    DWORD Reserved        : 30;
    DWORD D3IdleTimeout;
  } STORAGE_IDLE_POWER, *PSTORAGE_IDLE_POWER;

  typedef enum _STORAGE_POWERUP_REASON_TYPE
  {
    StoragePowerupUnknown = 0,
    StoragePowerupIO,
    StoragePowerupDeviceAttention
  } STORAGE_POWERUP_REASON_TYPE, *PSTORAGE_POWERUP_REASON_TYPE;

  typedef struct _STORAGE_IDLE_POWERUP_REASON
  {
    DWORD                       Version;
    DWORD                       Size;
    STORAGE_POWERUP_REASON_TYPE PowerupReason;
  } STORAGE_IDLE_POWERUP_REASON, *PSTORAGE_IDLE_POWERUP_REASON;

#define STORAGE_IDLE_POWERUP_REASON_VERSION_V1 1

  typedef enum _STORAGE_DEVICE_POWER_CAP_UNITS
  {
    StorageDevicePowerCapUnitsPercent,
    StorageDevicePowerCapUnitsMilliwatts
  } STORAGE_DEVICE_POWER_CAP_UNITS, *PSTORAGE_DEVICE_POWER_CAP_UNITS;

  typedef struct _STORAGE_DEVICE_POWER_CAP
  {
    DWORD                          Version;
    DWORD                          Size;
    STORAGE_DEVICE_POWER_CAP_UNITS Units;
    DWORDLONG                      MaxPower;
  } STORAGE_DEVICE_POWER_CAP, *PSTORAGE_DEVICE_POWER_CAP;

#define STORAGE_DEVICE_POWER_CAP_VERSION_V1 1

  typedef struct _STORAGE_RPMB_DATA_FRAME
  {
    BYTE Stuff[196];
    BYTE KeyOrMAC[32];
    BYTE Data[256];
    BYTE Nonce[16];
    BYTE WriteCounter[4];
    BYTE Address[2];
    BYTE BlockCount[2];
    BYTE OperationResult[2];
    BYTE RequestOrResponseType[2];
  } STORAGE_RPMB_DATA_FRAME, *PSTORAGE_RPMB_DATA_FRAME;

  typedef enum _STORAGE_RPMB_COMMAND_TYPE
  {
    StorRpmbProgramAuthKey                 = 0x00000001,
    StorRpmbQueryWriteCounter              = 0x00000002,
    StorRpmbAuthenticatedWrite             = 0x00000003,
    StorRpmbAuthenticatedRead              = 0x00000004,
    StorRpmbReadResultRequest              = 0x00000005,
    StorRpmbAuthenticatedDeviceConfigWrite = 0x00000006,
    StorRpmbAuthenticatedDeviceConfigRead  = 0x00000007,
  } STORAGE_RPMB_COMMAND_TYPE, *PSTORAGE_RPMB_COMMAND_TYPE;

  typedef struct _STORAGE_EVENT_NOTIFICATION
  {
    DWORD     Version;
    DWORD     Size;
    DWORDLONG Events;
  } STORAGE_EVENT_NOTIFICATION, *PSTORAGE_EVENT_NOTIFICATION;

#define STORAGE_EVENT_NOTIFICATION_VERSION_V1 1
#define STORAGE_EVENT_MEDIA_STATUS            0x0000000000000001
#define STORAGE_EVENT_DEVICE_STATUS           0x0000000000000002
#define STORAGE_EVENT_DEVICE_OPERATION        0x0000000000000004
#define STORAGE_EVENT_ALL                     (STORAGE_EVENT_MEDIA_STATUS | STORAGE_EVENT_DEVICE_STATUS | STORAGE_EVENT_DEVICE_OPERATION)

#define READ_COPY_NUMBER_KEY               0x52434e00
#define READ_COPY_NUMBER_BYPASS_CACHE_FLAG 0x00000100

#define IsKeyReadCopyNumber(_k)               (((_k) & 0xFFFFFE00) == READ_COPY_NUMBER_KEY)
#define IsKeyReadCopyNumberBypassCache(_k)    ((_k) & READ_COPY_NUMBER_BYPASS_CACHE_FLAG)
#define SetReadCopyNumberBypassCacheToKey(_k) ((_k) |= READ_COPY_NUMBER_BYPASS_CACHE_FLAG)
#define ReadCopyNumberToKey(_c)               (READ_COPY_NUMBER_KEY | (BYTE)(_c))
#define ReadCopyNumberFromKey(_k)             (BYTE)((_k) & 0x000000FF)

  typedef enum _STORAGE_COUNTER_TYPE
  {
    StorageCounterTypeUnknown = 0,
    StorageCounterTypeTemperatureCelsius,
    StorageCounterTypeTemperatureCelsiusMax,
    StorageCounterTypeReadErrorsTotal,
    StorageCounterTypeReadErrorsCorrected,
    StorageCounterTypeReadErrorsUncorrected,
    StorageCounterTypeWriteErrorsTotal,
    StorageCounterTypeWriteErrorsCorrected,
    StorageCounterTypeWriteErrorsUncorrected,
    StorageCounterTypeManufactureDate,
    StorageCounterTypeStartStopCycleCount,
    StorageCounterTypeStartStopCycleCountMax,
    StorageCounterTypeLoadUnloadCycleCount,
    StorageCounterTypeLoadUnloadCycleCountMax,
    StorageCounterTypeWearPercentage,
    StorageCounterTypeWearPercentageWarning,
    StorageCounterTypeWearPercentageMax,
    StorageCounterTypePowerOnHours,
    StorageCounterTypeReadLatency100NSMax,
    StorageCounterTypeWriteLatency100NSMax,
    StorageCounterTypeFlushLatency100NSMax,
    StorageCounterTypeMax
  } STORAGE_COUNTER_TYPE, *PSTORAGE_COUNTER_TYPE;

  typedef struct _STORAGE_COUNTER
  {
    STORAGE_COUNTER_TYPE Type;
    union
    {
      struct
      {
        DWORD Week;
        DWORD Year;
      } ManufactureDate;
      DWORDLONG AsUlonglong;
    } Value;
  } STORAGE_COUNTER, *PSTORAGE_COUNTER;

  typedef struct _STORAGE_COUNTERS
  {
    DWORD           Version;
    DWORD           Size;
    DWORD           NumberOfCounters;
    STORAGE_COUNTER Counters[ANYSIZE_ARRAY];
  } STORAGE_COUNTERS, *PSTORAGE_COUNTERS;

#define STORAGE_COUNTERS_VERSION_V1 sizeof(STORAGE_COUNTERS)

#define STORAGE_HW_FIRMWARE_REQUEST_FLAG_CONTROLLER                       0x00000001
#define STORAGE_HW_FIRMWARE_REQUEST_FLAG_LAST_SEGMENT                     0x00000002
#define STORAGE_HW_FIRMWARE_REQUEST_FLAG_FIRST_SEGMENT                    0x00000004
#define STORAGE_HW_FIRMWARE_REQUEST_FLAG_SWITCH_TO_FIRMWARE_WITHOUT_RESET 0x10000000
#define STORAGE_HW_FIRMWARE_REQUEST_FLAG_REPLACE_AND_SWITCH_UPON_RESET    0x20000000
#define STORAGE_HW_FIRMWARE_REQUEST_FLAG_REPLACE_EXISTING_IMAGE           0x40000000
#define STORAGE_HW_FIRMWARE_REQUEST_FLAG_SWITCH_TO_EXISTING_FIRMWARE      0x80000000
#define STORAGE_HW_FIRMWARE_INVALID_SLOT                                  0xFF
#define STORAGE_HW_FIRMWARE_REVISION_LENGTH                               16

  typedef struct _STORAGE_HW_FIRMWARE_INFO_QUERY
  {
    DWORD Version;
    DWORD Size;
    DWORD Flags;
    DWORD Reserved;
  } STORAGE_HW_FIRMWARE_INFO_QUERY, *PSTORAGE_HW_FIRMWARE_INFO_QUERY;

  typedef struct _STORAGE_HW_FIRMWARE_SLOT_INFO
  {
    DWORD Version;
    DWORD Size;
    BYTE  SlotNumber;
    BYTE  ReadOnly  : 1;
    BYTE  Reserved0 : 7;
    BYTE  Reserved1[6];
    BYTE  Revision[STORAGE_HW_FIRMWARE_REVISION_LENGTH];
  } STORAGE_HW_FIRMWARE_SLOT_INFO, *PSTORAGE_HW_FIRMWARE_SLOT_INFO;

  typedef struct _STORAGE_HW_FIRMWARE_INFO
  {
    DWORD                         Version;
    DWORD                         Size;
    BYTE                          SupportUpgrade : 1;
    BYTE                          Reserved0      : 7;
    BYTE                          SlotCount;
    BYTE                          ActiveSlot;
    BYTE                          PendingActivateSlot;
    BOOLEAN                       FirmwareShared;
    BYTE                          Reserved[3];
    DWORD                         ImagePayloadAlignment;
    DWORD                         ImagePayloadMaxSize;
    STORAGE_HW_FIRMWARE_SLOT_INFO Slot[ANYSIZE_ARRAY];
  } STORAGE_HW_FIRMWARE_INFO, *PSTORAGE_HW_FIRMWARE_INFO;

  typedef struct _STORAGE_HW_FIRMWARE_DOWNLOAD
  {
    DWORD     Version;
    DWORD     Size;
    DWORD     Flags;
    BYTE      Slot;
    BYTE      Reserved[3];
    DWORDLONG Offset;
    DWORDLONG BufferSize;
    BYTE      ImageBuffer[ANYSIZE_ARRAY];
  } STORAGE_HW_FIRMWARE_DOWNLOAD, *PSTORAGE_HW_FIRMWARE_DOWNLOAD;

  typedef struct _STORAGE_HW_FIRMWARE_DOWNLOAD_V2
  {
    DWORD     Version;
    DWORD     Size;
    DWORD     Flags;
    BYTE      Slot;
    BYTE      Reserved[3];
    DWORDLONG Offset;
    DWORDLONG BufferSize;
    DWORD     ImageSize;
    DWORD     Reserved2;
    BYTE      ImageBuffer[ANYSIZE_ARRAY];
  } STORAGE_HW_FIRMWARE_DOWNLOAD_V2, *PSTORAGE_HW_FIRMWARE_DOWNLOAD_V2;

  typedef struct _STORAGE_HW_FIRMWARE_ACTIVATE
  {
    DWORD Version;
    DWORD Size;
    DWORD Flags;
    BYTE  Slot;
    BYTE  Reserved0[3];
  } STORAGE_HW_FIRMWARE_ACTIVATE, *PSTORAGE_HW_FIRMWARE_ACTIVATE;

#define STORAGE_PROTOCOL_STRUCTURE_VERSION 0x1

  typedef struct _STORAGE_PROTOCOL_COMMAND
  {
    DWORD                 Version;
    DWORD                 Length;
    STORAGE_PROTOCOL_TYPE ProtocolType;
    DWORD Flags;
    DWORD ReturnStatus;
    DWORD ErrorCode;
    DWORD CommandLength;
    DWORD ErrorInfoLength;
    DWORD DataToDeviceTransferLength;
    DWORD DataFromDeviceTransferLength;
    DWORD TimeOutValue;
    DWORD ErrorInfoOffset;
    DWORD DataToDeviceBufferOffset;
    DWORD DataFromDeviceBufferOffset;
    DWORD CommandSpecific;
    DWORD Reserved0;
    DWORD FixedProtocolReturnData;
    DWORD FixedProtocolReturnData2;
    DWORD Reserved1[2];
    BYTE  Command[ANYSIZE_ARRAY];
  } STORAGE_PROTOCOL_COMMAND, *PSTORAGE_PROTOCOL_COMMAND;

#define STORAGE_PROTOCOL_COMMAND_FLAG_ADAPTER_REQUEST  0x80000000
#define STORAGE_PROTOCOL_STATUS_PENDING                0x0
#define STORAGE_PROTOCOL_STATUS_SUCCESS                0x1
#define STORAGE_PROTOCOL_STATUS_ERROR                  0x2
#define STORAGE_PROTOCOL_STATUS_INVALID_REQUEST        0x3
#define STORAGE_PROTOCOL_STATUS_NO_DEVICE              0x4
#define STORAGE_PROTOCOL_STATUS_BUSY                   0x5
#define STORAGE_PROTOCOL_STATUS_DATA_OVERRUN           0x6
#define STORAGE_PROTOCOL_STATUS_INSUFFICIENT_RESOURCES 0x7
#define STORAGE_PROTOCOL_STATUS_THROTTLED_REQUEST      0x8
#define STORAGE_PROTOCOL_STATUS_NOT_SUPPORTED          0xFF
#define STORAGE_PROTOCOL_COMMAND_LENGTH_NVME           0x40
#define STORAGE_PROTOCOL_SPECIFIC_NVME_ADMIN_COMMAND   0x01
#define STORAGE_PROTOCOL_SPECIFIC_NVME_NVM_COMMAND     0x02

  typedef enum _STORAGE_ATTRIBUTE_MGMT_ACTION
  {
    StorAttributeMgmt_ClearAttribute = 0,
    StorAttributeMgmt_SetAttribute   = 1,
    StorAttributeMgmt_ResetAttribute = 2
  } STORAGE_ATTRIBUTE_MGMT_ACTION, *PSTORAGE_ATTRIBUTE_MGMT_ACTION;

#define STORATTRIBUTE_NONE             0
#define STORATTRIBUTE_MANAGEMENT_STATE 1

  typedef struct _STORAGE_ATTRIBUTE_MGMT
  {
    DWORD                         Version;
    DWORD                         Size;
    STORAGE_ATTRIBUTE_MGMT_ACTION Action;
    DWORD                         Attribute;
  } STORAGE_ATTRIBUTE_MGMT, *PSTORAGE_ATTRIBUTE_MGMT;

#ifdef __cplusplus
}
#endif

#endif  /* _NTDDSTOR_H_ */

#ifndef _NTDDSCM_H_
#define _NTDDSCM_H_

#define IOCTL_SCMBUS_BASE                       FILE_DEVICE_PERSISTENT_MEMORY
#define IOCTL_SCMBUS_DEVICE_FUNCTION_BASE       0x0
#define IOCTL_SCM_LOGICAL_DEVICE_FUNCTION_BASE  0x300
#define IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE 0x600

#define SCMBUS_FUNCTION(x)              (IOCTL_SCMBUS_DEVICE_FUNCTION_BASE       + x)
#define SCM_LOGICAL_DEVICE_FUNCTION(x)  (IOCTL_SCM_LOGICAL_DEVICE_FUNCTION_BASE  + x)
#define SCM_PHYSICAL_DEVICE_FUNCTION(x) (IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + x)

#define IOCTL_SCM_BUS_GET_LOGICAL_DEVICES     CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(0x00),              METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_BUS_GET_PHYSICAL_DEVICES    CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(0x01),              METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_BUS_GET_REGIONS             CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(0x02),              METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_BUS_QUERY_PROPERTY          CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(0x03),              METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_BUS_SET_PROPERTY            CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(0x05),              METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_SCM_BUS_RUNTIME_FW_ACTIVATE     CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(0x04),              METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_SCM_BUS_REFRESH_NAMESPACE       CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(0x06),              METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_LD_GET_INTERLEAVE_SET       CTL_CODE(IOCTL_SCMBUS_BASE, SCM_LOGICAL_DEVICE_FUNCTION(0x00),  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_PD_QUERY_PROPERTY           CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(0x00), METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_PD_FIRMWARE_DOWNLOAD        CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(0x01), METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_SCM_PD_FIRMWARE_ACTIVATE        CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(0x02), METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_SCM_PD_PASSTHROUGH              CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(0x03), METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_SCM_PD_UPDATE_MANAGEMENT_STATUS CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(0x04), METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCM_PD_REINITIALIZE_MEDIA       CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(0x05), METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_SCM_PD_SET_PROPERTY             CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(0x06), METHOD_BUFFERED, FILE_WRITE_ACCESS)

  typedef struct _SCM_PD_HEALTH_NOTIFICATION_DATA
  {
    GUID  DeviceGuid;
  } SCM_PD_HEALTH_NOTIFICATION_DATA, *PSCM_PD_HEALTH_NOTIFICATION_DATA;

#define SCM_MAX_SYMLINK_LEN_IN_CHARS 256

  typedef struct _SCM_LOGICAL_DEVICE_INSTANCE
  {
    DWORD Version;
    DWORD Size;
    GUID  DeviceGuid;
    WCHAR SymbolicLink[SCM_MAX_SYMLINK_LEN_IN_CHARS];
  } SCM_LOGICAL_DEVICE_INSTANCE, *PSCM_LOGICAL_DEVICE_INSTANCE;

  typedef struct _SCM_LOGICAL_DEVICES
  {
    DWORD                       Version;
    DWORD                       Size;
    DWORD                       DeviceCount;
    SCM_LOGICAL_DEVICE_INSTANCE Devices[ANYSIZE_ARRAY];
  } SCM_LOGICAL_DEVICES, *PSCM_LOGICAL_DEVICES;

  typedef struct _SCM_PHYSICAL_DEVICE_INSTANCE
  {
    DWORD Version;
    DWORD Size;
    DWORD NfitHandle;
    WCHAR SymbolicLink[SCM_MAX_SYMLINK_LEN_IN_CHARS];
  } SCM_PHYSICAL_DEVICE_INSTANCE, *PSCM_PHYSICAL_DEVICE_INSTANCE;

  typedef struct _SCM_PHYSICAL_DEVICES
  {
    DWORD                        Version;
    DWORD                        Size;
    DWORD                        DeviceCount;
    SCM_PHYSICAL_DEVICE_INSTANCE Devices[ANYSIZE_ARRAY];
  } SCM_PHYSICAL_DEVICES, *PSCM_PHYSICAL_DEVICES;

  typedef enum _SCM_REGION_FLAG
  {
    ScmRegionFlagNone  = 0x0,
    ScmRegionFlagLabel = 0x1
  } SCM_REGION_FLAG, *PSCM_REGION_FLAG;

#define SCM_REGION_SPA_UNKNOWN MAXDWORD64

  typedef struct _SCM_REGION
  {
    DWORD   Version;
    DWORD   Size;
    DWORD   Flags;
    DWORD   NfitHandle;
    GUID    LogicalDeviceGuid;
    GUID    AddressRangeType;
    DWORD   AssociatedId;
    DWORD64 Length;
    DWORD64 StartingDPA;
    DWORD64 BaseSPA;
    DWORD64 SPAOffset;
    DWORD64 RegionOffset;
  } SCM_REGION, *PSCM_REGION;

  typedef struct _SCM_REGIONS
  {
    DWORD      Version;
    DWORD      Size;
    DWORD      RegionCount;
    SCM_REGION Regions[ANYSIZE_ARRAY];
  } SCM_REGIONS, *PSCM_REGIONS;

  typedef enum _SCM_BUS_QUERY_TYPE
  {
    ScmBusQuery_Descriptor = 0,
    ScmBusQuery_IsSupported,
    ScmBusQuery_Max
  } SCM_BUS_QUERY_TYPE, *PSCM_BUS_QUERY_TYPE;

  typedef enum _SCM_BUS_SET_TYPE
  {
    ScmBusSet_Descriptor = 0,
    ScmBusSet_IsSupported,
    ScmBusSet_Max
  } SCM_BUS_SET_TYPE, *PSCM_BUS_SET_TYPE;

  typedef enum _SCM_BUS_PROPERTY_ID
  {
    ScmBusProperty_RuntimeFwActivationInfo = 0,
    ScmBusProperty_DedicatedMemoryInfo     = 1,
    ScmBusProperty_DedicatedMemoryState    = 2,
    ScmBusProperty_Max
  } SCM_BUS_PROPERTY_ID, *PSCM_BUS_PROPERTY_ID;

  typedef struct _SCM_BUS_PROPERTY_QUERY
  {
    DWORD               Version;
    DWORD               Size;
    SCM_BUS_PROPERTY_ID PropertyId;
    SCM_BUS_QUERY_TYPE  QueryType;
    BYTE                AdditionalParameters[ANYSIZE_ARRAY];
  } SCM_BUS_PROPERTY_QUERY, *PSCM_BUS_PROPERTY_QUERY;

  typedef enum _SCM_BUS_FIRMWARE_ACTIVATION_STATE
  {
    ScmBusFirmwareActivationState_Idle  = 0,
    ScmBusFirmwareActivationState_Armed = 1,
    ScmBusFirmwareActivationState_Busy  = 2
  } SCM_BUS_FIRMWARE_ACTIVATION_STATE, *PSCM_BUS_FIRMWARE_ACTIVATION_STATE;

  typedef struct _SCM_BUS_RUNTIME_FW_ACTIVATION_INFO
  {
    DWORD                             Version;
    DWORD                             Size;
    BOOLEAN                           RuntimeFwActivationSupported;
    SCM_BUS_FIRMWARE_ACTIVATION_STATE FirmwareActivationState;
    struct
    {
      DWORD FwManagedIoQuiesceFwActivationSupported : 1;
      DWORD OsManagedIoQuiesceFwActivationSupported : 1;
      DWORD WarmResetBasedFwActivationSupported     : 1;
      DWORD Reserved                                : 29;
    } FirmwareActivationCapability;
    DWORDLONG EstimatedFirmwareActivationTimeInUSecs;
    DWORDLONG EstimatedProcessorAccessQuiesceTimeInUSecs;
    DWORDLONG EstimatedIOAccessQuiesceTimeInUSecs;
    DWORDLONG PlatformSupportedMaxIOAccessQuiesceTimeInUSecs;
  } SCM_BUS_RUNTIME_FW_ACTIVATION_INFO, *PSCM_BUS_RUNTIME_FW_ACTIVATION_INFO;

  typedef struct _SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO
  {
    GUID  DeviceGuid;
    DWORD DeviceNumber;
    struct
    {
      DWORD ForcedByRegistry : 1;
      DWORD Initialized      : 1;
      DWORD Reserved         : 30;
    } Flags;
    DWORDLONG DeviceSize;
  } SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO, *PSCM_BUS_DEDICATED_MEMORY_DEVICE_INFO;

  typedef struct _SCM_BUS_DEDICATED_MEMORY_DEVICES_INFO
  {
    DWORD                                Version;
    DWORD                                Size;
    DWORD                                DeviceCount;
    SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO Devices[ANYSIZE_ARRAY];
  } SCM_BUS_DEDICATED_MEMORY_DEVICES_INFO, *PSCM_BUS_DEDICATED_MEMORY_DEVICES_INFO;

  typedef struct _SCM_BUS_PROPERTY_SET
  {
    DWORD               Version;
    DWORD               Size;
    SCM_BUS_PROPERTY_ID PropertyId;
    SCM_BUS_SET_TYPE    SetType;
    BYTE                AdditionalParameters[ANYSIZE_ARRAY];
  } SCM_BUS_PROPERTY_SET, *PSCM_BUS_PROPERTY_SET;

  typedef struct _SCM_BUS_DEDICATED_MEMORY_STATE
  {
    BOOLEAN ActivateState;
  } SCM_BUS_DEDICATED_MEMORY_STATE, *PSCM_BUS_DEDICATED_MEMORY_STATE;

  typedef struct _SCM_INTERLEAVED_PD_INFO
  {
    DWORD DeviceHandle;
    GUID  DeviceGuid;
  } SCM_INTERLEAVED_PD_INFO, *PSCM_INTERLEAVED_PD_INFO;

  typedef struct _SCM_LD_INTERLEAVE_SET_INFO
  {
    DWORD                   Version;
    DWORD                   Size;
    DWORD                   InterleaveSetSize;
    SCM_INTERLEAVED_PD_INFO InterleaveSet[ANYSIZE_ARRAY];
  } SCM_LD_INTERLEAVE_SET_INFO, *PSCM_LD_INTERLEAVE_SET_INFO;

  typedef enum _SCM_PD_QUERY_TYPE
  {
    ScmPhysicalDeviceQuery_Descriptor = 0,
    ScmPhysicalDeviceQuery_IsSupported,
    ScmPhysicalDeviceQuery_Max
  } SCM_PD_QUERY_TYPE, *PSCM_PD_QUERY_TYPE;

  typedef enum _SCM_PD_SET_TYPE
  {
    ScmPhysicalDeviceSet_Descriptor = 0,
    ScmPhysicalDeviceSet_IsSupported,
    ScmPhysicalDeviceSet_Max
  } SCM_PD_SET_TYPE, *PSCM_PD_SET_TYPE;

  typedef enum _SCM_PD_PROPERTY_ID
  {
    ScmPhysicalDeviceProperty_DeviceInfo = 0,
    ScmPhysicalDeviceProperty_ManagementStatus,
    ScmPhysicalDeviceProperty_FirmwareInfo,
    ScmPhysicalDeviceProperty_LocationString,
    ScmPhysicalDeviceProperty_DeviceSpecificInfo,
    ScmPhysicalDeviceProperty_DeviceHandle,
    ScmPhysicalDeviceProperty_FruIdString,
    ScmPhysicalDeviceProperty_RuntimeFwActivationInfo,
    ScmPhysicalDeviceProperty_RuntimeFwActivationArmState,
    ScmPhysicalDeviceProperty_Max
  } SCM_PD_PROPERTY_ID, *PSCM_PD_PROPERTY_ID;

  typedef struct _SCM_PD_PROPERTY_QUERY
  {
    DWORD              Version;
    DWORD              Size;
    SCM_PD_PROPERTY_ID PropertyId;
    SCM_PD_QUERY_TYPE  QueryType;
    BYTE               AdditionalParameters[ANYSIZE_ARRAY];
  } SCM_PD_PROPERTY_QUERY, *PSCM_PD_PROPERTY_QUERY;

  typedef struct _SCM_PD_PROPERTY_SET
  {
    DWORD              Version;
    DWORD              Size;
    SCM_PD_PROPERTY_ID PropertyId;
    SCM_PD_SET_TYPE    SetType;
    BYTE               AdditionalParameters[ANYSIZE_ARRAY];
  } SCM_PD_PROPERTY_SET, *PSCM_PD_PROPERTY_SET;

  typedef struct _SCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE
  {
    BOOLEAN ArmState;
  } SCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE, *PSCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE;

  typedef struct _SCM_PD_DESCRIPTOR_HEADER
  {
    DWORD Version;
    DWORD Size;
  } SCM_PD_DESCRIPTOR_HEADER, *PSCM_PD_DESCRIPTOR_HEADER;

  typedef struct _SCM_PD_DEVICE_HANDLE
  {
    DWORD Version;
    DWORD Size;
    GUID  DeviceGuid;
    DWORD DeviceHandle;
  } SCM_PD_DEVICE_HANDLE, *PSCM_PD_DEVICE_HANDLE;

#define MAX_INTERFACE_CODES                   8
#define SCM_PD_FIRMWARE_REVISION_LENGTH_BYTES 32
#define SCM_PD_MEMORY_SIZE_UNKNOWN            MAXDWORD64
#define SCM_PD_PROPERTY_NAME_LENGTH_IN_CHARS  128

  typedef struct _SCM_PD_DEVICE_INFO
  {
    DWORD   Version;
    DWORD   Size;
    GUID    DeviceGuid;
    DWORD   UnsafeShutdownCount;
    DWORD64 PersistentMemorySizeInBytes;
    DWORD64 VolatileMemorySizeInBytes;
    DWORD64 TotalMemorySizeInBytes;
    DWORD   SlotNumber;
    DWORD   DeviceHandle;
    WORD    PhysicalId;
    BYTE    NumberOfFormatInterfaceCodes;
    WORD    FormatInterfaceCodes[MAX_INTERFACE_CODES];
    DWORD   VendorId;
    DWORD   ProductId;
    DWORD   SubsystemDeviceId;
    DWORD   SubsystemVendorId;
    BYTE    ManufacturingLocation;
    BYTE    ManufacturingWeek;
    BYTE    ManufacturingYear;
    DWORD   SerialNumber4Byte;
    DWORD   SerialNumberLengthInChars;
    CHAR    SerialNumber[ANYSIZE_ARRAY];
  } SCM_PD_DEVICE_INFO, *PSCM_PD_DEVICE_INFO;

  typedef struct _SCM_PD_DEVICE_SPECIFIC_PROPERTY
  {
    WCHAR    Name[SCM_PD_PROPERTY_NAME_LENGTH_IN_CHARS];
    LONGLONG Value;
  } SCM_PD_DEVICE_SPECIFIC_PROPERTY, *PSCM_PD_DEVICE_SPECIFIC_PROPERTY;

  typedef struct _SCM_PD_DEVICE_SPECIFIC_INFO
  {
    DWORD                           Version;
    DWORD                           Size;
    DWORD                           NumberOfProperties;
    SCM_PD_DEVICE_SPECIFIC_PROPERTY DeviceSpecificProperties[ANYSIZE_ARRAY];
  } SCM_PD_DEVICE_SPECIFIC_INFO, *PSCM_PD_DEVICE_SPECIFIC_INFO;

  typedef struct _SCM_PD_FIRMWARE_SLOT_INFO
  {
    DWORD Version;
    DWORD Size;
    BYTE  SlotNumber;
    BYTE  ReadOnly  : 1;
    BYTE  Reserved0 : 7;
    BYTE  Reserved1[6];
    BYTE  Revision[SCM_PD_FIRMWARE_REVISION_LENGTH_BYTES];
  } SCM_PD_FIRMWARE_SLOT_INFO, *PSCM_PD_FIRMWARE_SLOT_INFO;

  typedef struct _SCM_PD_FIRMWARE_INFO
  {
    DWORD                     Version;
    DWORD                     Size;
    BYTE                      ActiveSlot;
    BYTE                      NextActiveSlot;
    BYTE                      SlotCount;
    SCM_PD_FIRMWARE_SLOT_INFO Slots[ANYSIZE_ARRAY];
  } SCM_PD_FIRMWARE_INFO, *PSCM_PD_FIRMWARE_INFO;

  typedef enum _SCM_PD_HEALTH_STATUS
  {
    ScmPhysicalDeviceHealth_Unknown = 0,
    ScmPhysicalDeviceHealth_Unhealthy,
    ScmPhysicalDeviceHealth_Warning,
    ScmPhysicalDeviceHealth_Healthy,
    ScmPhysicalDeviceHealth_Max
  } SCM_PD_HEALTH_STATUS, *PSCM_PD_HEALTH_STATUS;

  typedef enum _SCM_PD_OPERATIONAL_STATUS
  {
    ScmPhysicalDeviceOpStatus_Unknown = 0,
    ScmPhysicalDeviceOpStatus_Ok,
    ScmPhysicalDeviceOpStatus_PredictingFailure,
    ScmPhysicalDeviceOpStatus_InService,
    ScmPhysicalDeviceOpStatus_HardwareError,
    ScmPhysicalDeviceOpStatus_NotUsable,
    ScmPhysicalDeviceOpStatus_TransientError,
    ScmPhysicalDeviceOpStatus_Missing,
    ScmPhysicalDeviceOpStatus_Max
  } SCM_PD_OPERATIONAL_STATUS, *PSCM_PD_OPERATIONAL_STATUS;

  typedef enum _SCM_PD_OPERATIONAL_STATUS_REASON
  {
    ScmPhysicalDeviceOpReason_Unknown = 0,
    ScmPhysicalDeviceOpReason_Media,
    ScmPhysicalDeviceOpReason_ThresholdExceeded,
    ScmPhysicalDeviceOpReason_LostData,
    ScmPhysicalDeviceOpReason_EnergySource,
    ScmPhysicalDeviceOpReason_Configuration,
    ScmPhysicalDeviceOpReason_DeviceController,
    ScmPhysicalDeviceOpReason_MediaController,
    ScmPhysicalDeviceOpReason_Component,
    ScmPhysicalDeviceOpReason_BackgroundOperation,
    ScmPhysicalDeviceOpReason_InvalidFirmware,
    ScmPhysicalDeviceOpReason_HealthCheck,
    ScmPhysicalDeviceOpReason_LostDataPersistence,
    ScmPhysicalDeviceOpReason_DisabledByPlatform,
    ScmPhysicalDeviceOpReason_PermanentError,
    ScmPhysicalDeviceOpReason_LostWritePersistence,
    ScmPhysicalDeviceOpReason_FatalError,
    ScmPhysicalDeviceOpReason_DataPersistenceLossImminent,
    ScmPhysicalDeviceOpReason_WritePersistenceLossImminent,
    ScmPhysicalDeviceOpReason_MediaRemainingSpareBlock,
    ScmPhysicalDeviceOpReason_PerformanceDegradation,
    ScmPhysicalDeviceOpReason_ExcessiveTemperature,
    ScmPhysicalDeviceOpReason_InternalFailure,
    ScmPhysicalDeviceOpReason_Max
  } SCM_PD_OPERATIONAL_STATUS_REASON, *PSCM_PD_OPERATIONAL_STATUS_REASON;

#define SCM_PD_MAX_OPERATIONAL_STATUS 16

  typedef struct _SCM_PD_MANAGEMENT_STATUS
  {
    DWORD                            Version;
    DWORD                            Size;
    SCM_PD_HEALTH_STATUS             Health;
    DWORD                            NumberOfOperationalStatus;
    DWORD                            NumberOfAdditionalReasons;
    SCM_PD_OPERATIONAL_STATUS        OperationalStatus[SCM_PD_MAX_OPERATIONAL_STATUS];
    SCM_PD_OPERATIONAL_STATUS_REASON AdditionalReasons[ANYSIZE_ARRAY];
  } SCM_PD_MANAGEMENT_STATUS, *PSCM_PD_MANAGEMENT_STATUS;

  typedef struct _SCM_PD_LOCATION_STRING
  {
    DWORD Version;
    DWORD Size;
    WCHAR Location[ANYSIZE_ARRAY];
  } SCM_PD_LOCATION_STRING, *PSCM_PD_LOCATION_STRING;

  typedef struct _SCM_PD_FRU_ID_STRING
  {
    DWORD Version;
    DWORD Size;
    DWORD IdentifierSize;
    BYTE  Identifier[ANYSIZE_ARRAY];
  } SCM_PD_FRU_ID_STRING, *PSCM_PD_FRU_ID_STRING;

#define SCM_PD_FIRMWARE_LAST_DOWNLOAD 0x1

  typedef struct _SCM_PD_FIRMWARE_DOWNLOAD
  {
    DWORD   Version;
    DWORD   Size;
    DWORD   Flags;
    BYTE    Slot;
    BYTE    Reserved[3];
    DWORD64 Offset;
    DWORD   FirmwareImageSizeInBytes;
    BYTE    FirmwareImage[ANYSIZE_ARRAY];
  } SCM_PD_FIRMWARE_DOWNLOAD, *PSCM_PD_FIRMWARE_DOWNLOAD;

  typedef struct _SCM_PD_FIRMWARE_ACTIVATE
  {
    DWORD Version;
    DWORD Size;
    DWORD Flags;
    BYTE  Slot;
  } SCM_PD_FIRMWARE_ACTIVATE, *PSCM_PD_FIRMWARE_ACTIVATE;

  typedef enum _SCM_PD_LAST_FW_ACTIVATION_STATUS
  {
    ScmPdLastFwActivationStatus_None                 = 0,
    ScmPdLastFwActivationStatus_Success              = 1,
    ScmPdLastFwActivationStatus_FwNotFound           = 2,
    ScmPdLastFwActivationStatus_ColdRebootRequired   = 3,
    ScmPdLastFwActivaitonStatus_ActivationInProgress = 4,
    ScmPdLastFwActivaitonStatus_Retry                = 5,
    ScmPdLastFwActivaitonStatus_FwUnsupported        = 6,
    ScmPdLastFwActivaitonStatus_UnknownError         = 7
  } SCM_PD_LAST_FW_ACTIVATION_STATUS, *PSCM_PD_LAST_FW_ACTIVATION_STATUS;

  typedef enum _SCM_PD_FIRMWARE_ACTIVATION_STATE
  {
    ScmPdFirmwareActivationState_Idle  = 0,
    ScmPdFirmwareActivationState_Armed = 1,
    ScmPdFirmwareActivationState_Busy  = 2
  } SCM_PD_FIRMWARE_ACTIVATION_STATE, *PSCM_PD_FIRMWARE_ACTIVATION_STATE;

  typedef struct _SCM_PD_RUNTIME_FW_ACTIVATION_INFO
  {
    DWORD                            Version;
    DWORD                            Size;
    SCM_PD_LAST_FW_ACTIVATION_STATUS LastFirmwareActivationStatus;
    SCM_PD_FIRMWARE_ACTIVATION_STATE FirmwareActivationState;
  } SCM_PD_RUNTIME_FW_ACTIVATION_INFO, *PSCM_PD_RUNTIME_FW_ACTIVATION_INFO;

  typedef struct _SCM_PD_PASSTHROUGH_INPUT
  {
    DWORD Version;
    DWORD Size;
    GUID  ProtocolGuid;
    DWORD DataSize;
    BYTE  Data[ANYSIZE_ARRAY];
  } SCM_PD_PASSTHROUGH_INPUT, *PSCM_PD_PASSTHROUGH_INPUT;

  typedef struct _SCM_PD_PASSTHROUGH_OUTPUT
  {
    DWORD Version;
    DWORD Size;
    GUID  ProtocolGuid;
    DWORD DataSize;
    BYTE  Data[ANYSIZE_ARRAY];
  } SCM_PD_PASSTHROUGH_OUTPUT, *PSCM_PD_PASSTHROUGH_OUTPUT;

  typedef struct _SCM_PD_PASSTHROUGH_INVDIMM_INPUT
  {
    DWORD Opcode;
    DWORD OpcodeParametersLength;
    BYTE  OpcodeParameters[ANYSIZE_ARRAY];
  } SCM_PD_PASSTHROUGH_INVDIMM_INPUT, *PSCM_PD_PASSTHROUGH_INVDIMM_INPUT;

  typedef struct _SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT
  {
    WORD  GeneralStatus;
    WORD  ExtendedStatus;
    DWORD OutputDataLength;
    BYTE  OutputData[ANYSIZE_ARRAY];
  } SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT, *PSCM_PD_PASSTHROUGH_INVDIMM_OUTPUT;

  typedef struct _SCM_PD_REINITIALIZE_MEDIA_INPUT
  {
    DWORD Version;
    DWORD Size;
    struct
    {
      DWORD Overwrite : 1;
    } Options;
  } SCM_PD_REINITIALIZE_MEDIA_INPUT, *PSCM_PD_REINITIALIZE_MEDIA_INPUT;

  typedef enum _SCM_PD_MEDIA_REINITIALIZATION_STATUS
  {
    ScmPhysicalDeviceReinit_Success = 0,
    ScmPhysicalDeviceReinit_RebootNeeded,
    ScmPhysicalDeviceReinit_ColdBootNeeded,
    ScmPhysicalDeviceReinit_Max
  } SCM_PD_MEDIA_REINITIALIZATION_STATUS, *PSCM_PD_MEDIA_REINITIALIZATION_STATUS;

  typedef struct _SCM_PD_REINITIALIZE_MEDIA_OUTPUT
  {
    DWORD                                Version;
    DWORD                                Size;
    SCM_PD_MEDIA_REINITIALIZATION_STATUS Status;
  } SCM_PD_REINITIALIZE_MEDIA_OUTPUT, *PSCM_PD_REINITIALIZE_MEDIA_OUTPUT;

#endif  /* _NTDDSCM_H_ */

#ifndef _NTDDDISK_H_
#define _NTDDDISK_H_

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#define IOCTL_DISK_BASE                     FILE_DEVICE_DISK
#define IOCTL_DISK_GET_DRIVE_GEOMETRY       CTL_CODE(IOCTL_DISK_BASE, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_GET_PARTITION_INFO       CTL_CODE(IOCTL_DISK_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_SET_PARTITION_INFO       CTL_CODE(IOCTL_DISK_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_GET_DRIVE_LAYOUT         CTL_CODE(IOCTL_DISK_BASE, 0x0003, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_SET_DRIVE_LAYOUT         CTL_CODE(IOCTL_DISK_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_VERIFY                   CTL_CODE(IOCTL_DISK_BASE, 0x0005, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_FORMAT_TRACKS            CTL_CODE(IOCTL_DISK_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_REASSIGN_BLOCKS          CTL_CODE(IOCTL_DISK_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_PERFORMANCE              CTL_CODE(IOCTL_DISK_BASE, 0x0008, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_IS_WRITABLE              CTL_CODE(IOCTL_DISK_BASE, 0x0009, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_LOGGING                  CTL_CODE(IOCTL_DISK_BASE, 0x000a, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_FORMAT_TRACKS_EX         CTL_CODE(IOCTL_DISK_BASE, 0x000b, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_HISTOGRAM_STRUCTURE      CTL_CODE(IOCTL_DISK_BASE, 0x000c, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_HISTOGRAM_DATA           CTL_CODE(IOCTL_DISK_BASE, 0x000d, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_HISTOGRAM_RESET          CTL_CODE(IOCTL_DISK_BASE, 0x000e, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_REQUEST_STRUCTURE        CTL_CODE(IOCTL_DISK_BASE, 0x000f, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_REQUEST_DATA             CTL_CODE(IOCTL_DISK_BASE, 0x0010, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_PERFORMANCE_OFF          CTL_CODE(IOCTL_DISK_BASE, 0x0018, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_CONTROLLER_NUMBER        CTL_CODE(IOCTL_DISK_BASE, 0x0011, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SMART_GET_VERSION                   CTL_CODE(IOCTL_DISK_BASE, 0x0020, METHOD_BUFFERED, FILE_READ_ACCESS)
#define SMART_SEND_DRIVE_COMMAND            CTL_CODE(IOCTL_DISK_BASE, 0x0021, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define SMART_RCV_DRIVE_DATA                CTL_CODE(IOCTL_DISK_BASE, 0x0022, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define SMART_RCV_DRIVE_DATA_EX             CTL_CODE(IOCTL_DISK_BASE, 0x0023, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_GET_PARTITION_INFO_EX    CTL_CODE(IOCTL_DISK_BASE, 0x0012, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_SET_PARTITION_INFO_EX    CTL_CODE(IOCTL_DISK_BASE, 0x0013, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_GET_DRIVE_LAYOUT_EX      CTL_CODE(IOCTL_DISK_BASE, 0x0014, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_SET_DRIVE_LAYOUT_EX      CTL_CODE(IOCTL_DISK_BASE, 0x0015, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_CREATE_DISK              CTL_CODE(IOCTL_DISK_BASE, 0x0016, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_GET_LENGTH_INFO          CTL_CODE(IOCTL_DISK_BASE, 0x0017, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_GET_DRIVE_GEOMETRY_EX    CTL_CODE(IOCTL_DISK_BASE, 0x0028, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_REASSIGN_BLOCKS_EX       CTL_CODE(IOCTL_DISK_BASE, 0x0029, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_UPDATE_DRIVE_SIZE        CTL_CODE(IOCTL_DISK_BASE, 0x0032, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_GROW_PARTITION           CTL_CODE(IOCTL_DISK_BASE, 0x0034, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_GET_CACHE_INFORMATION    CTL_CODE(IOCTL_DISK_BASE, 0x0035, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_SET_CACHE_INFORMATION    CTL_CODE(IOCTL_DISK_BASE, 0x0036, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define OBSOLETE_DISK_GET_WRITE_CACHE_STATE CTL_CODE(IOCTL_DISK_BASE, 0x0037, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_DELETE_DRIVE_LAYOUT      CTL_CODE(IOCTL_DISK_BASE, 0x0040, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_UPDATE_PROPERTIES        CTL_CODE(IOCTL_DISK_BASE, 0x0050, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_FORMAT_DRIVE             CTL_CODE(IOCTL_DISK_BASE, 0x00f3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_DISK_SENSE_DEVICE             CTL_CODE(IOCTL_DISK_BASE, 0x00f8, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_CHECK_VERIFY             CTL_CODE(IOCTL_DISK_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_MEDIA_REMOVAL            CTL_CODE(IOCTL_DISK_BASE, 0x0201, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_EJECT_MEDIA              CTL_CODE(IOCTL_DISK_BASE, 0x0202, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_LOAD_MEDIA               CTL_CODE(IOCTL_DISK_BASE, 0x0203, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_RESERVE                  CTL_CODE(IOCTL_DISK_BASE, 0x0204, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_RELEASE                  CTL_CODE(IOCTL_DISK_BASE, 0x0205, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_FIND_NEW_DEVICES         CTL_CODE(IOCTL_DISK_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_DISK_GET_MEDIA_TYPES          CTL_CODE(IOCTL_DISK_BASE, 0x0300, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define PARTITION_ENTRY_UNUSED    0x00
#define PARTITION_FAT_12          0x01
#define PARTITION_XENIX_1         0x02
#define PARTITION_XENIX_2         0x03
#define PARTITION_FAT_16          0x04
#define PARTITION_EXTENDED        0x05
#define PARTITION_HUGE            0x06
#define PARTITION_IFS             0x07
#define PARTITION_OS2BOOTMGR      0x0A
#define PARTITION_FAT32           0x0B
#define PARTITION_FAT32_XINT13    0x0C
#define PARTITION_XINT13          0x0E
#define PARTITION_XINT13_EXTENDED 0x0F
#define PARTITION_MSFT_RECOVERY   0x27
#define PARTITION_MAIN_OS         0x28
#define PARTIITON_OS_DATA         0x29
#define PARTITION_PRE_INSTALLED   0x2a
#define PARTITION_BSP             0x2b
#define PARTITION_DPP             0x2c
#define PARTITION_WINDOWS_SYSTEM  0x2d
#define PARTITION_PREP            0x41
#define PARTITION_LDM             0x42
#define PARTITION_DM              0x54
#define PARTITION_EZDRIVE         0x55
#define PARTITION_UNIX            0x63
#define PARTITION_SPACES_DATA     0xD7
#define PARTITION_SPACES          0xE7
#define PARTITION_GPT             0xEE
#define PARTITION_SYSTEM          0xEF
#define VALID_NTFT                0xC0
#define PARTITION_NTFT            0x80

#define IsRecognizedPartition(PartitionType)         \
  (                                                  \
    ((PartitionType) == PARTITION_BSP)            || \
    ((PartitionType) == PARTITION_DPP)            || \
    ((PartitionType) == PARTITION_FAT_12)         || \
    ((PartitionType) == PARTITION_FAT_16)         || \
    ((PartitionType) == PARTITION_FAT32)          || \
    ((PartitionType) == PARTITION_FAT32_XINT13)   || \
    ((PartitionType) == PARTITION_HUGE)           || \
    ((PartitionType) == PARTITION_IFS)            || \
    ((PartitionType) == PARTITION_MAIN_OS)        || \
    ((PartitionType) == PARTITION_MSFT_RECOVERY)  || \
    ((PartitionType) == PARTIITON_OS_DATA)        || \
    ((PartitionType) == PARTITION_PRE_INSTALLED)  || \
    ((PartitionType) == PARTITION_SYSTEM)         || \
    ((PartitionType) == PARTITION_WINDOWS_SYSTEM) || \
    ((PartitionType) == PARTITION_XINT13)            \
  )
#define IsContainerPartition(PartitionType) ((PartitionType == PARTITION_EXTENDED) || (PartitionType == PARTITION_XINT13_EXTENDED))
#define IsFTPartition(PartitionType)                         \
  (                                                          \
    (PartitionType & PARTITION_NTFT) &&                      \
    (                                                        \
      ((PartitionType & ~0xC0) == PARTITION_HUGE)         || \
      ((PartitionType & ~0xC0) == PARTITION_IFS)          || \
      ((PartitionType & ~0xC0) == PARTITION_FAT32)        || \
      ((PartitionType & ~0xC0) == PARTITION_FAT32_XINT13)    \
    )                                                        \
  )

  typedef enum _MEDIA_TYPE
  {
    Unknown,
    F5_1Pt2_512,
    F3_1Pt44_512,
    F3_2Pt88_512,
    F3_20Pt8_512,
    F3_720_512,
    F5_360_512,
    F5_320_512,
    F5_320_1024,
    F5_180_512,
    F5_160_512,
    RemovableMedia,
    FixedMedia,
    F3_120M_512,
    F3_640_512,
    F5_640_512,
    F5_720_512,
    F3_1Pt2_512,
    F3_1Pt23_1024,
    F5_1Pt23_1024,
    F3_128Mb_512,
    F3_230Mb_512,
    F8_256_128,
    F3_200Mb_512,
    F3_240M_512,
    F3_32M_512
  } MEDIA_TYPE, *PMEDIA_TYPE;

  typedef struct _FORMAT_PARAMETERS
  {
  MEDIA_TYPE MediaType;
  DWORD      StartCylinderNumber;
  DWORD      EndCylinderNumber;
  DWORD      StartHeadNumber;
  DWORD      EndHeadNumber;
  } FORMAT_PARAMETERS, *PFORMAT_PARAMETERS;

  typedef WORD  BAD_TRACK_NUMBER;
  typedef WORD *PBAD_TRACK_NUMBER;

  typedef struct _FORMAT_EX_PARAMETERS
  {
    MEDIA_TYPE MediaType;
    DWORD      StartCylinderNumber;
    DWORD      EndCylinderNumber;
    DWORD      StartHeadNumber;
    DWORD      EndHeadNumber;
    WORD       FormatGapLength;
    WORD       SectorsPerTrack;
    WORD       SectorNumber[1];
  } FORMAT_EX_PARAMETERS, *PFORMAT_EX_PARAMETERS;

  typedef struct _DISK_GEOMETRY
  {
    LARGE_INTEGER Cylinders;
    MEDIA_TYPE    MediaType;
    DWORD         TracksPerCylinder;
    DWORD         SectorsPerTrack;
    DWORD         BytesPerSector;
  } DISK_GEOMETRY, *PDISK_GEOMETRY;

#define WMI_DISK_GEOMETRY_GUID {0x25007f51, 0x57c2, 0x11d1, {0xa5, 0x28, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0x10}}

  typedef struct _PARTITION_INFORMATION
  {
    LARGE_INTEGER StartingOffset;
    LARGE_INTEGER PartitionLength;
    DWORD         HiddenSectors;
    DWORD         PartitionNumber;
    BYTE          PartitionType;
    BOOLEAN       BootIndicator;
    BOOLEAN       RecognizedPartition;
    BOOLEAN       RewritePartition;
  } PARTITION_INFORMATION, *PPARTITION_INFORMATION;

  typedef struct _SET_PARTITION_INFORMATION
  {
    BYTE PartitionType;
  } SET_PARTITION_INFORMATION, *PSET_PARTITION_INFORMATION;

  typedef struct _DRIVE_LAYOUT_INFORMATION
  {
    DWORD                 PartitionCount;
    DWORD                 Signature;
    PARTITION_INFORMATION PartitionEntry[1];
  } DRIVE_LAYOUT_INFORMATION, *PDRIVE_LAYOUT_INFORMATION;

  typedef struct _VERIFY_INFORMATION
  {
    LARGE_INTEGER StartingOffset;
    DWORD         Length;
  } VERIFY_INFORMATION, *PVERIFY_INFORMATION;

  typedef struct _REASSIGN_BLOCKS
  {
    WORD  Reserved;
    WORD  Count;
    DWORD BlockNumber[1];
  } REASSIGN_BLOCKS, *PREASSIGN_BLOCKS;

#include <pshpack1.h>

  typedef struct _REASSIGN_BLOCKS_EX
  {
    WORD          Reserved;
    WORD          Count;
    LARGE_INTEGER BlockNumber[1];
  } REASSIGN_BLOCKS_EX, *PREASSIGN_BLOCKS_EX;

#include <poppack.h>

  typedef enum _PARTITION_STYLE
  {
    PARTITION_STYLE_MBR,
    PARTITION_STYLE_GPT,
    PARTITION_STYLE_RAW
  } PARTITION_STYLE;

  typedef struct _PARTITION_INFORMATION_GPT
  {
    GUID    PartitionType;
    GUID    PartitionId;
    DWORD64 Attributes;
    WCHAR   Name[36];
  } PARTITION_INFORMATION_GPT, *PPARTITION_INFORMATION_GPT;

#define GPT_ATTRIBUTE_PLATFORM_REQUIRED          (0x0000000000000001)
#define GPT_ATTRIBUTE_NO_BLOCK_IO_PROTOCOL       (0x0000000000000002)
#define GPT_ATTRIBUTE_LEGACY_BIOS_BOOTABLE       (0x0000000000000004)
#define GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER (0x8000000000000000)
#define GPT_BASIC_DATA_ATTRIBUTE_HIDDEN          (0x4000000000000000)
#define GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY     (0x2000000000000000)
#define GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY       (0x1000000000000000)
#define GPT_BASIC_DATA_ATTRIBUTE_OFFLINE         (0x0800000000000000)
#define GPT_BASIC_DATA_ATTRIBUTE_DAX             (0x0400000000000000)
#define GPT_BASIC_DATA_ATTRIBUTE_SERVICE         (0x0200000000000000)
#define GPT_SPACES_ATTRIBUTE_NO_METADATA         (0x8000000000000000)

  typedef struct _PARTITION_INFORMATION_MBR
  {
    BYTE    PartitionType;
    BOOLEAN BootIndicator;
    BOOLEAN RecognizedPartition;
    DWORD   HiddenSectors;
    GUID    PartitionId;
  } PARTITION_INFORMATION_MBR, *PPARTITION_INFORMATION_MBR;

  typedef SET_PARTITION_INFORMATION SET_PARTITION_INFORMATION_MBR;
  typedef PARTITION_INFORMATION_GPT SET_PARTITION_INFORMATION_GPT;

  typedef struct _SET_PARTITION_INFORMATION_EX
  {
    PARTITION_STYLE PartitionStyle;
    __C89_NAMELESS union
    {
      SET_PARTITION_INFORMATION_MBR Mbr;
      SET_PARTITION_INFORMATION_GPT Gpt;
    } DUMMYUNIONNAME;
  } SET_PARTITION_INFORMATION_EX, *PSET_PARTITION_INFORMATION_EX;

  typedef struct _CREATE_DISK_GPT
  {
    GUID  DiskId;
    DWORD MaxPartitionCount;
  } CREATE_DISK_GPT, *PCREATE_DISK_GPT;

  typedef struct _CREATE_DISK_MBR
  {
    DWORD Signature;
  } CREATE_DISK_MBR, *PCREATE_DISK_MBR;

  typedef struct _CREATE_DISK
  {
    PARTITION_STYLE PartitionStyle;
    __C89_NAMELESS union
    {
      CREATE_DISK_MBR Mbr;
      CREATE_DISK_GPT Gpt;
    } DUMMYUNIONNAME;
  } CREATE_DISK, *PCREATE_DISK;

  typedef struct _GET_LENGTH_INFORMATION
  {
    LARGE_INTEGER Length;
  } GET_LENGTH_INFORMATION, *PGET_LENGTH_INFORMATION;

  typedef struct _PARTITION_INFORMATION_EX
  {
    PARTITION_STYLE PartitionStyle;
    LARGE_INTEGER   StartingOffset;
    LARGE_INTEGER   PartitionLength;
    DWORD           PartitionNumber;
    BOOLEAN         RewritePartition;
    BOOLEAN         IsServicePartition;
    __C89_NAMELESS union
    {
      PARTITION_INFORMATION_MBR Mbr;
      PARTITION_INFORMATION_GPT Gpt;
    } DUMMYUNIONNAME;
  } PARTITION_INFORMATION_EX, *PPARTITION_INFORMATION_EX;

  typedef struct _DRIVE_LAYOUT_INFORMATION_GPT
  {
    GUID          DiskId;
    LARGE_INTEGER StartingUsableOffset;
    LARGE_INTEGER UsableLength;
    DWORD         MaxPartitionCount;
  } DRIVE_LAYOUT_INFORMATION_GPT, *PDRIVE_LAYOUT_INFORMATION_GPT;

  typedef struct _DRIVE_LAYOUT_INFORMATION_MBR
  {
    DWORD Signature;
    DWORD CheckSum;
  } DRIVE_LAYOUT_INFORMATION_MBR, *PDRIVE_LAYOUT_INFORMATION_MBR;

  typedef struct _DRIVE_LAYOUT_INFORMATION_EX
  {
    DWORD PartitionStyle;
    DWORD PartitionCount;
    __C89_NAMELESS union
    {
      DRIVE_LAYOUT_INFORMATION_MBR Mbr;
      DRIVE_LAYOUT_INFORMATION_GPT Gpt;
    } DUMMYUNIONNAME;
    PARTITION_INFORMATION_EX PartitionEntry[1];
  } DRIVE_LAYOUT_INFORMATION_EX, *PDRIVE_LAYOUT_INFORMATION_EX;

  typedef enum _DETECTION_TYPE
  {
    DetectNone,
    DetectInt13,
    DetectExInt13
  } DETECTION_TYPE;

  typedef struct _DISK_INT13_INFO
  {
    WORD  DriveSelect;
    DWORD MaxCylinders;
    WORD  SectorsPerTrack;
    WORD  MaxHeads;
    WORD  NumberDrives;
  } DISK_INT13_INFO, *PDISK_INT13_INFO;

  typedef struct _DISK_EX_INT13_INFO
  {
    WORD    ExBufferSize;
    WORD    ExFlags;
    DWORD   ExCylinders;
    DWORD   ExHeads;
    DWORD   ExSectorsPerTrack;
    DWORD64 ExSectorsPerDrive;
    WORD    ExSectorSize;
    WORD    ExReserved;
  } DISK_EX_INT13_INFO, *PDISK_EX_INT13_INFO;

  typedef struct _DISK_DETECTION_INFO
  {
    DWORD          SizeOfDetectInfo;
    DETECTION_TYPE DetectionType;
    __C89_NAMELESS union
    {
      __C89_NAMELESS struct
      {
        DISK_INT13_INFO    Int13;
        DISK_EX_INT13_INFO ExInt13;
      } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
  } DISK_DETECTION_INFO, *PDISK_DETECTION_INFO;

  typedef struct _DISK_PARTITION_INFO
  {
    DWORD           SizeOfPartitionInfo;
    PARTITION_STYLE PartitionStyle;
    __C89_NAMELESS union
    {
      struct
      {
        DWORD Signature;
        DWORD CheckSum;
      } Mbr;
      struct
      {
        GUID DiskId;
      } Gpt;
    } DUMMYUNIONNAME;
  } DISK_PARTITION_INFO, *PDISK_PARTITION_INFO;

#define DiskGeometryGetPartition(Geometry) ((PDISK_PARTITION_INFO)((Geometry)->Data))
#define DiskGeometryGetDetect(Geometry)    ((PDISK_DETECTION_INFO)(((DWORD_PTR)DiskGeometryGetPartition(Geometry) + DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))

  typedef struct _DISK_GEOMETRY_EX
  {
    DISK_GEOMETRY Geometry;
    LARGE_INTEGER DiskSize;
    BYTE          Data[1];
  } DISK_GEOMETRY_EX, *PDISK_GEOMETRY_EX;

  typedef struct _DISK_CONTROLLER_NUMBER
  {
    DWORD ControllerNumber;
    DWORD DiskNumber;
  } DISK_CONTROLLER_NUMBER, *PDISK_CONTROLLER_NUMBER;

  typedef enum
  {
    EqualPriority,
    KeepPrefetchedData,
    KeepReadData
  } DISK_CACHE_RETENTION_PRIORITY;

  typedef struct _DISK_CACHE_INFORMATION
  {
    BOOLEAN                       ParametersSavable;
    BOOLEAN                       ReadCacheEnabled;
    BOOLEAN                       WriteCacheEnabled;
    DISK_CACHE_RETENTION_PRIORITY ReadRetentionPriority;
    DISK_CACHE_RETENTION_PRIORITY WriteRetentionPriority;
    WORD                          DisablePrefetchTransferLength;
    BOOLEAN                       PrefetchScalar;
    __C89_NAMELESS union
    {
      struct
      {
        WORD Minimum;
        WORD Maximum;
        WORD MaximumBlocks;
      } ScalarPrefetch;
      struct
      {
        WORD Minimum;
        WORD Maximum;
      } BlockPrefetch;
    } DUMMYUNIONNAME;
  } DISK_CACHE_INFORMATION, *PDISK_CACHE_INFORMATION;

  typedef struct _DISK_GROW_PARTITION
  {
    DWORD         PartitionNumber;
    LARGE_INTEGER BytesToGrow;
  } DISK_GROW_PARTITION, *PDISK_GROW_PARTITION;

#define HIST_NO_OF_BUCKETS 24

  typedef struct _HISTOGRAM_BUCKET
  {
    DWORD Reads;
    DWORD Writes;
  } HISTOGRAM_BUCKET, *PHISTOGRAM_BUCKET;

#define HISTOGRAM_BUCKET_SIZE sizeof(HISTOGRAM_BUCKET)

  typedef struct _DISK_HISTOGRAM
  {
    LARGE_INTEGER     DiskSize;
    LARGE_INTEGER     Start;
    LARGE_INTEGER     End;
    LARGE_INTEGER     Average;
    LARGE_INTEGER     AverageRead;
    LARGE_INTEGER     AverageWrite;
    DWORD             Granularity;
    DWORD             Size;
    DWORD             ReadCount;
    DWORD             WriteCount;
    PHISTOGRAM_BUCKET Histogram;
  } DISK_HISTOGRAM, *PDISK_HISTOGRAM;

#define DISK_HISTOGRAM_SIZE sizeof(DISK_HISTOGRAM)

  typedef struct _DISK_PERFORMANCE
  {
    LARGE_INTEGER BytesRead;
    LARGE_INTEGER BytesWritten;
    LARGE_INTEGER ReadTime;
    LARGE_INTEGER WriteTime;
    LARGE_INTEGER IdleTime;
    DWORD         ReadCount;
    DWORD         WriteCount;
    DWORD         QueueDepth;
    DWORD         SplitCount;
    LARGE_INTEGER QueryTime;
    DWORD         StorageDeviceNumber;
    WCHAR         StorageManagerName[8];
  } DISK_PERFORMANCE, *PDISK_PERFORMANCE;

  typedef struct _DISK_RECORD
  {
    LARGE_INTEGER ByteOffset;
    LARGE_INTEGER StartTime;
    LARGE_INTEGER EndTime;
    PVOID         VirtualAddress;
    DWORD         NumberOfBytes;
    BYTE          DeviceNumber;
    BOOLEAN       ReadRequest;
  } DISK_RECORD, *PDISK_RECORD;

  typedef struct _DISK_LOGGING
  {
    BYTE  Function;
    PVOID BufferAddress;
    DWORD BufferSize;
  } DISK_LOGGING, *PDISK_LOGGING;

#define DISK_LOGGING_START 0
#define DISK_LOGGING_STOP  1
#define DISK_LOGGING_DUMP  2
#define DISK_BINNING       3

  typedef enum _BIN_TYPES
  {
    RequestSize,
    RequestLocation
  } BIN_TYPES;

  typedef struct _BIN_RANGE
  {
    LARGE_INTEGER StartValue;
    LARGE_INTEGER Length;
  } BIN_RANGE, *PBIN_RANGE;

  typedef struct _PERF_BIN
  {
    DWORD     NumberOfBins;
    DWORD     TypeOfBin;
    BIN_RANGE BinsRanges[1];
  } PERF_BIN, *PPERF_BIN;

  typedef struct _BIN_COUNT
  {
    BIN_RANGE BinRange;
    DWORD     BinCount;
  } BIN_COUNT, *PBIN_COUNT;

  typedef struct _BIN_RESULTS
  {
    DWORD     NumberOfBins;
    BIN_COUNT BinCounts[1];
  } BIN_RESULTS, *PBIN_RESULTS;

#include <pshpack1.h>

  typedef struct _GETVERSIONINPARAMS
  {
    BYTE  bVersion;
    BYTE  bRevision;
    BYTE  bReserved;
    BYTE  bIDEDeviceMap;
    DWORD fCapabilities;
    DWORD dwReserved[4];
  } GETVERSIONINPARAMS, *PGETVERSIONINPARAMS, *LPGETVERSIONINPARAMS;

#include <poppack.h>

#define CAP_ATA_ID_CMD   1
#define CAP_ATAPI_ID_CMD 2
#define CAP_SMART_CMD    4

#include <pshpack1.h>

  typedef struct _IDEREGS
  {
    BYTE bFeaturesReg;
    BYTE bSectorCountReg;
    BYTE bSectorNumberReg;
    BYTE bCylLowReg;
    BYTE bCylHighReg;
    BYTE bDriveHeadReg;
    BYTE bCommandReg;
    BYTE bReserved;
  } IDEREGS, *PIDEREGS, *LPIDEREGS;

#include <poppack.h>

#define ATAPI_ID_CMD  0xA1
#define ID_CMD        0xEC
#define SMART_CMD     0xB0
#define SMART_CYL_LOW 0x4F
#define SMART_CYL_HI  0xC2

#include <pshpack1.h>

  typedef struct _SENDCMDINPARAMS
  {
    DWORD   cBufferSize;
    IDEREGS irDriveRegs;
    BYTE    bDriveNumber;
    BYTE    bReserved[3];
    DWORD   dwReserved[4];
    BYTE    bBuffer[1];
  } SENDCMDINPARAMS, *PSENDCMDINPARAMS, *LPSENDCMDINPARAMS;

#include <poppack.h>

#include <pshpack1.h>

  typedef struct _DRIVERSTATUS
  {
    BYTE  bDriverError;
    BYTE  bIDEError;
    BYTE  bReserved[2];
    DWORD dwReserved[2];
  } DRIVERSTATUS, *PDRIVERSTATUS, *LPDRIVERSTATUS;

#include <poppack.h>

#define SMART_NO_ERROR                  0
#define SMART_IDE_ERROR                 1
#define SMART_INVALID_FLAG              2
#define SMART_INVALID_COMMAND           3
#define SMART_INVALID_BUFFER            4
#define SMART_INVALID_DRIVE             5
#define SMART_INVALID_IOCTL             6
#define SMART_ERROR_NO_MEM              7
#define SMART_INVALID_REGISTER          8
#define SMART_NOT_SUPPORTED             9
#define SMART_NO_IDE_DEVICE             10
#define SMART_OFFLINE_ROUTINE_OFFLINE   0
#define SMART_SHORT_SELFTEST_OFFLINE    1
#define SMART_EXTENDED_SELFTEST_OFFLINE 2
#define SMART_ABORT_OFFLINE_SELFTEST    127
#define SMART_SHORT_SELFTEST_CAPTIVE    129
#define SMART_EXTENDED_SELFTEST_CAPTIVE 130

#include <pshpack1.h>

  typedef struct _SENDCMDOUTPARAMS
  {
    DWORD        cBufferSize;
    DRIVERSTATUS DriverStatus;
    BYTE         bBuffer[1];
  } SENDCMDOUTPARAMS, *PSENDCMDOUTPARAMS, *LPSENDCMDOUTPARAMS;

#include <poppack.h>

#define READ_ATTRIBUTE_BUFFER_SIZE 512
#define IDENTIFY_BUFFER_SIZE       512
#define READ_THRESHOLD_BUFFER_SIZE 512
#define SMART_LOG_SECTOR_SIZE      512

#define READ_ATTRIBUTES             0xD0
#define READ_THRESHOLDS             0xD1
#define ENABLE_DISABLE_AUTOSAVE     0xD2
#define SAVE_ATTRIBUTE_VALUES       0xD3
#define EXECUTE_OFFLINE_DIAGS       0xD4
#define SMART_READ_LOG              0xD5
#define SMART_WRITE_LOG             0xd6
#define ENABLE_SMART                0xD8
#define DISABLE_SMART               0xD9
#define RETURN_SMART_STATUS         0xDA
#define ENABLE_DISABLE_AUTO_OFFLINE 0xDB

#define IOCTL_DISK_GET_DISK_ATTRIBUTES CTL_CODE(IOCTL_DISK_BASE, 0x003c, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_DISK_SET_DISK_ATTRIBUTES CTL_CODE(IOCTL_DISK_BASE, 0x003d, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define DISK_ATTRIBUTE_OFFLINE   0x0000000000000001
#define DISK_ATTRIBUTE_READ_ONLY 0x0000000000000002

  typedef struct _GET_DISK_ATTRIBUTES
  {
    DWORD     Version;
    DWORD     Reserved1;
    DWORDLONG Attributes;
  } GET_DISK_ATTRIBUTES, *PGET_DISK_ATTRIBUTES;

  typedef struct _SET_DISK_ATTRIBUTES
  {
    DWORD     Version;
    BOOLEAN   Persist;
    BYTE      Reserved1[3];
    DWORDLONG Attributes;
    DWORDLONG AttributesMask;
    DWORD     Reserved2[4];
  } SET_DISK_ATTRIBUTES, *PSET_DISK_ATTRIBUTES;

#define IOCTL_DISK_RESET_SNAPSHOT_INFO CTL_CODE(IOCTL_DISK_BASE, 0x0084, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#endif /* _NTDDDISK_H_ */

#define IOCTL_CHANGER_BASE                      FILE_DEVICE_CHANGER
#define IOCTL_CHANGER_GET_PARAMETERS            CTL_CODE(IOCTL_CHANGER_BASE, 0x0000, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_GET_STATUS                CTL_CODE(IOCTL_CHANGER_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_GET_PRODUCT_DATA          CTL_CODE(IOCTL_CHANGER_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_SET_ACCESS                CTL_CODE(IOCTL_CHANGER_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_CHANGER_GET_ELEMENT_STATUS        CTL_CODE(IOCTL_CHANGER_BASE, 0x0005, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS CTL_CODE(IOCTL_CHANGER_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_SET_POSITION              CTL_CODE(IOCTL_CHANGER_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_EXCHANGE_MEDIUM           CTL_CODE(IOCTL_CHANGER_BASE, 0x0008, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_MOVE_MEDIUM               CTL_CODE(IOCTL_CHANGER_BASE, 0x0009, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_REINITIALIZE_TRANSPORT    CTL_CODE(IOCTL_CHANGER_BASE, 0x000A, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CHANGER_QUERY_VOLUME_TAGS         CTL_CODE(IOCTL_CHANGER_BASE, 0x000B, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define MAX_VOLUME_ID_SIZE       36
#define MAX_VOLUME_TEMPLATE_SIZE 40

#define VENDOR_ID_LENGTH     8
#define PRODUCT_ID_LENGTH    16
#define REVISION_LENGTH      4
#define SERIAL_NUMBER_LENGTH 32

  typedef enum _ELEMENT_TYPE
  {
    AllElements,
    ChangerTransport,
    ChangerSlot,
    ChangerIEPort,
    ChangerDrive,
    ChangerDoor,
    ChangerKeypad,
    ChangerMaxElement
  } ELEMENT_TYPE, *PELEMENT_TYPE;

  typedef struct _CHANGER_ELEMENT
  {
    ELEMENT_TYPE ElementType;
    DWORD        ElementAddress;
  } CHANGER_ELEMENT, *PCHANGER_ELEMENT;

  typedef struct _CHANGER_ELEMENT_LIST
  {
    CHANGER_ELEMENT Element;
    DWORD           NumberOfElements;
  } CHANGER_ELEMENT_LIST, *PCHANGER_ELEMENT_LIST;

#define CHANGER_BAR_CODE_SCANNER_INSTALLED  0x00000001
#define CHANGER_INIT_ELEM_STAT_WITH_RANGE   0x00000002
#define CHANGER_CLOSE_IEPORT                0x00000004
#define CHANGER_OPEN_IEPORT                 0x00000008
#define CHANGER_STATUS_NON_VOLATILE         0x00000010
#define CHANGER_EXCHANGE_MEDIA              0x00000020
#define CHANGER_CLEANER_SLOT                0x00000040
#define CHANGER_LOCK_UNLOCK                 0x00000080
#define CHANGER_CARTRIDGE_MAGAZINE          0x00000100
#define CHANGER_MEDIUM_FLIP                 0x00000200
#define CHANGER_POSITION_TO_ELEMENT         0x00000400
#define CHANGER_REPORT_IEPORT_STATE         0x00000800
#define CHANGER_STORAGE_DRIVE               0x00001000
#define CHANGER_STORAGE_IEPORT              0x00002000
#define CHANGER_STORAGE_SLOT                0x00004000
#define CHANGER_STORAGE_TRANSPORT           0x00008000
#define CHANGER_DRIVE_CLEANING_REQUIRED     0x00010000
#define CHANGER_PREDISMOUNT_EJECT_REQUIRED  0x00020000
#define CHANGER_CLEANER_ACCESS_NOT_VALID    0x00040000
#define CHANGER_PREMOUNT_EJECT_REQUIRED     0x00080000
#define CHANGER_VOLUME_IDENTIFICATION       0x00100000
#define CHANGER_VOLUME_SEARCH               0x00200000
#define CHANGER_VOLUME_ASSERT               0x00400000
#define CHANGER_VOLUME_REPLACE              0x00800000
#define CHANGER_VOLUME_UNDEFINE             0x01000000
#define CHANGER_SERIAL_NUMBER_VALID         0x04000000
#define CHANGER_DEVICE_REINITIALIZE_CAPABLE 0x08000000
#define CHANGER_KEYPAD_ENABLE_DISABLE       0x10000000
#define CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS  0x20000000
#define CHANGER_RESERVED_BIT                0x80000000
#define CHANGER_PREDISMOUNT_ALIGN_TO_SLOT   0x80000001
#define CHANGER_PREDISMOUNT_ALIGN_TO_DRIVE  0x80000002
#define CHANGER_CLEANER_AUTODISMOUNT        0x80000004
#define CHANGER_TRUE_EXCHANGE_CAPABLE       0x80000008
#define CHANGER_SLOTS_USE_TRAYS             0x80000010
#define CHANGER_RTN_MEDIA_TO_ORIGINAL_ADDR  0x80000020
#define CHANGER_CLEANER_OPS_NOT_SUPPORTED   0x80000040
#define CHANGER_IEPORT_USER_CONTROL_OPEN    0x80000080
#define CHANGER_IEPORT_USER_CONTROL_CLOSE   0x80000100
#define CHANGER_MOVE_EXTENDS_IEPORT         0x80000200
#define CHANGER_MOVE_RETRACTS_IEPORT        0x80000400

#define CHANGER_TO_TRANSPORT 0x01
#define CHANGER_TO_SLOT      0x02
#define CHANGER_TO_IEPORT    0x04
#define CHANGER_TO_DRIVE     0x08

#define LOCK_UNLOCK_IEPORT 0x01
#define LOCK_UNLOCK_DOOR   0x02
#define LOCK_UNLOCK_KEYPAD 0x04

  typedef struct _GET_CHANGER_PARAMETERS
  {
    DWORD Size;
    WORD  NumberTransportElements;
    WORD  NumberStorageElements;
    WORD  NumberCleanerSlots;
    WORD  NumberIEElements;
    WORD  NumberDataTransferElements;
    WORD  NumberOfDoors;
    WORD  FirstSlotNumber;
    WORD  FirstDriveNumber;
    WORD  FirstTransportNumber;
    WORD  FirstIEPortNumber;
    WORD  FirstCleanerSlotAddress;
    WORD  MagazineSize;
    DWORD DriveCleanTimeout;
    DWORD Features0;
    DWORD Features1;
    BYTE  MoveFromTransport;
    BYTE  MoveFromSlot;
    BYTE  MoveFromIePort;
    BYTE  MoveFromDrive;
    BYTE  ExchangeFromTransport;
    BYTE  ExchangeFromSlot;
    BYTE  ExchangeFromIePort;
    BYTE  ExchangeFromDrive;
    BYTE  LockUnlockCapabilities;
    BYTE  PositionCapabilities;
    BYTE  Reserved1[2];
    DWORD Reserved2[2];
  } GET_CHANGER_PARAMETERS, *PGET_CHANGER_PARAMETERS;

  typedef struct _CHANGER_PRODUCT_DATA
  {
    BYTE VendorId[VENDOR_ID_LENGTH];
    BYTE ProductId[PRODUCT_ID_LENGTH];
    BYTE Revision[REVISION_LENGTH];
    BYTE SerialNumber[SERIAL_NUMBER_LENGTH];
    BYTE DeviceType;
  } CHANGER_PRODUCT_DATA, *PCHANGER_PRODUCT_DATA;

#define LOCK_ELEMENT   0
#define UNLOCK_ELEMENT 1
#define EXTEND_IEPORT  2
#define RETRACT_IEPORT 3

  typedef struct _CHANGER_SET_ACCESS
  {
    CHANGER_ELEMENT Element;
    DWORD           Control;
  } CHANGER_SET_ACCESS, *PCHANGER_SET_ACCESS;

  typedef struct _CHANGER_READ_ELEMENT_STATUS
  {
    CHANGER_ELEMENT_LIST ElementList;
    BOOLEAN              VolumeTagInfo;
  } CHANGER_READ_ELEMENT_STATUS, *PCHANGER_READ_ELEMENT_STATUS;

  typedef struct _CHANGER_ELEMENT_STATUS
  {
    CHANGER_ELEMENT Element;
    CHANGER_ELEMENT SrcElementAddress;
    DWORD           Flags;
    DWORD           ExceptionCode;
    BYTE            TargetId;
    BYTE            Lun;
    WORD            Reserved;
    BYTE            PrimaryVolumeID[MAX_VOLUME_ID_SIZE];
    BYTE            AlternateVolumeID[MAX_VOLUME_ID_SIZE];
  } CHANGER_ELEMENT_STATUS, *PCHANGER_ELEMENT_STATUS;

  typedef struct _CHANGER_ELEMENT_STATUS_EX
  {
    CHANGER_ELEMENT Element;
    CHANGER_ELEMENT SrcElementAddress;
    DWORD           Flags;
    DWORD           ExceptionCode;
    BYTE            TargetId;
    BYTE            Lun;
    WORD            Reserved;
    BYTE            PrimaryVolumeID[MAX_VOLUME_ID_SIZE];
    BYTE            AlternateVolumeID[MAX_VOLUME_ID_SIZE];
    BYTE            VendorIdentification[VENDOR_ID_LENGTH];
    BYTE            ProductIdentification[PRODUCT_ID_LENGTH];
    BYTE            SerialNumber[SERIAL_NUMBER_LENGTH];
  } CHANGER_ELEMENT_STATUS_EX, *PCHANGER_ELEMENT_STATUS_EX;

#define ELEMENT_STATUS_FULL         0x00000001
#define ELEMENT_STATUS_IMPEXP       0x00000002
#define ELEMENT_STATUS_EXCEPT       0x00000004
#define ELEMENT_STATUS_ACCESS       0x00000008
#define ELEMENT_STATUS_EXENAB       0x00000010
#define ELEMENT_STATUS_INENAB       0x00000020
#define ELEMENT_STATUS_PRODUCT_DATA 0x00000040
#define ELEMENT_STATUS_LUN_VALID    0x00001000
#define ELEMENT_STATUS_ID_VALID     0x00002000
#define ELEMENT_STATUS_NOT_BUS      0x00008000
#define ELEMENT_STATUS_INVERT       0x00400000
#define ELEMENT_STATUS_SVALID       0x00800000
#define ELEMENT_STATUS_PVOLTAG      0x10000000
#define ELEMENT_STATUS_AVOLTAG      0x20000000

#define ERROR_LABEL_UNREADABLE    0x00000001
#define ERROR_LABEL_QUESTIONABLE  0x00000002
#define ERROR_SLOT_NOT_PRESENT    0x00000004
#define ERROR_DRIVE_NOT_INSTALLED 0x00000008
#define ERROR_TRAY_MALFUNCTION    0x00000010
#define ERROR_INIT_STATUS_NEEDED  0x00000011
#define ERROR_UNHANDLED_ERROR     0xFFFFFFFF

  typedef struct _CHANGER_INITIALIZE_ELEMENT_STATUS
  {
    CHANGER_ELEMENT_LIST ElementList;
    BOOLEAN              BarCodeScan;
  } CHANGER_INITIALIZE_ELEMENT_STATUS, *PCHANGER_INITIALIZE_ELEMENT_STATUS;

  typedef struct _CHANGER_SET_POSITION
  {
    CHANGER_ELEMENT Transport;
    CHANGER_ELEMENT Destination;
    BOOLEAN         Flip;
  } CHANGER_SET_POSITION, *PCHANGER_SET_POSITION;

  typedef struct _CHANGER_EXCHANGE_MEDIUM
  {
    CHANGER_ELEMENT Transport;
    CHANGER_ELEMENT Source;
    CHANGER_ELEMENT Destination1;
    CHANGER_ELEMENT Destination2;
    BOOLEAN         Flip1;
    BOOLEAN         Flip2;
  } CHANGER_EXCHANGE_MEDIUM, *PCHANGER_EXCHANGE_MEDIUM;

  typedef struct _CHANGER_MOVE_MEDIUM
  {
    CHANGER_ELEMENT Transport;
    CHANGER_ELEMENT Source;
    CHANGER_ELEMENT Destination;
    BOOLEAN         Flip;
  } CHANGER_MOVE_MEDIUM, *PCHANGER_MOVE_MEDIUM;

  typedef struct _CHANGER_SEND_VOLUME_TAG_INFORMATION
  {
    CHANGER_ELEMENT StartingElement;
    DWORD           ActionCode;
    BYTE            VolumeIDTemplate[MAX_VOLUME_TEMPLATE_SIZE];
  } CHANGER_SEND_VOLUME_TAG_INFORMATION, *PCHANGER_SEND_VOLUME_TAG_INFORMATION;

  typedef struct _READ_ELEMENT_ADDRESS_INFO
  {
    DWORD                  NumberOfElements;
    CHANGER_ELEMENT_STATUS ElementStatus[1];
  } READ_ELEMENT_ADDRESS_INFO, *PREAD_ELEMENT_ADDRESS_INFO;

#define SEARCH_ALL         0x0
#define SEARCH_PRIMARY     0x1
#define SEARCH_ALTERNATE   0x2
#define SEARCH_ALL_NO_SEQ  0x4
#define SEARCH_PRI_NO_SEQ  0x5
#define SEARCH_ALT_NO_SEQ  0x6
#define ASSERT_PRIMARY     0x8
#define ASSERT_ALTERNATE   0x9
#define REPLACE_PRIMARY    0xA
#define REPLACE_ALTERNATE  0xB
#define UNDEFINE_PRIMARY   0xC
#define UNDEFINE_ALTERNATE 0xD

  typedef enum _CHANGER_DEVICE_PROBLEM_TYPE
  {
    DeviceProblemNone,
    DeviceProblemHardware,
    DeviceProblemCHMError,
    DeviceProblemDoorOpen,
    DeviceProblemCalibrationError,
    DeviceProblemTargetFailure,
    DeviceProblemCHMMoveError,
    DeviceProblemCHMZeroError,
    DeviceProblemCartridgeInsertError,
    DeviceProblemPositionError,
    DeviceProblemSensorError,
    DeviceProblemCartridgeEjectError,
    DeviceProblemGripperError,
    DeviceProblemDriveError
  } CHANGER_DEVICE_PROBLEM_TYPE, *PCHANGER_DEVICE_PROBLEM_TYPE;

#define IOCTL_SERIAL_LSRMST_INSERT    CTL_CODE(FILE_DEVICE_SERIAL_PORT, 31,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERENUM_EXPOSE_HARDWARE CTL_CODE(FILE_DEVICE_SERENUM,     128, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERENUM_REMOVE_HARDWARE CTL_CODE(FILE_DEVICE_SERENUM,     129, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERENUM_PORT_DESC       CTL_CODE(FILE_DEVICE_SERENUM,     130, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SERENUM_GET_PORT_NAME   CTL_CODE(FILE_DEVICE_SERENUM,     131, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SERIAL_LSRMST_ESCAPE     ((BYTE)0x00)
#define SERIAL_LSRMST_LSR_DATA   ((BYTE)0x01)
#define SERIAL_LSRMST_LSR_NODATA ((BYTE)0x02)
#define SERIAL_LSRMST_MST        ((BYTE)0x03)

#define SERIAL_IOC_FCR_FIFO_ENABLE      ((DWORD)0x00000001)
#define SERIAL_IOC_FCR_RCVR_RESET       ((DWORD)0x00000002)
#define SERIAL_IOC_FCR_XMIT_RESET       ((DWORD)0x00000004)
#define SERIAL_IOC_FCR_DMA_MODE         ((DWORD)0x00000008)
#define SERIAL_IOC_FCR_RES1             ((DWORD)0x00000010)
#define SERIAL_IOC_FCR_RES2             ((DWORD)0x00000020)
#define SERIAL_IOC_FCR_RCVR_TRIGGER_LSB ((DWORD)0x00000040)
#define SERIAL_IOC_FCR_RCVR_TRIGGER_MSB ((DWORD)0x00000080)
#define SERIAL_IOC_MCR_DTR              ((DWORD)0x00000001)
#define SERIAL_IOC_MCR_RTS              ((DWORD)0x00000002)
#define SERIAL_IOC_MCR_OUT1             ((DWORD)0x00000004)
#define SERIAL_IOC_MCR_OUT2             ((DWORD)0x00000008)
#define SERIAL_IOC_MCR_LOOP             ((DWORD)0x00000010)

#ifndef _FILESYSTEMFSCTL_
#define _FILESYSTEMFSCTL_

#define FSCTL_REQUEST_OPLOCK_LEVEL_1                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 0,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REQUEST_OPLOCK_LEVEL_2                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 1,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REQUEST_BATCH_OPLOCK                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 2,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_OPLOCK_BREAK_ACKNOWLEDGE                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 3,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_OPBATCH_ACK_CLOSE_PENDING                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 4,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_OPLOCK_BREAK_NOTIFY                              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 5,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_LOCK_VOLUME                                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 6,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_UNLOCK_VOLUME                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 7,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DISMOUNT_VOLUME                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 8,   METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_IS_VOLUME_MOUNTED                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 10,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_IS_PATHNAME_VALID                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 11,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_MARK_VOLUME_DIRTY                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 12,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_RETRIEVAL_POINTERS                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 14,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_GET_COMPRESSION                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 15,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_COMPRESSION                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16,  METHOD_BUFFERED,   FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_SET_BOOTLOADER_ACCESSED                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 19,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_MARK_AS_SYSTEM_HIVE                              FSCTL_SET_BOOTLOADER_ACCESSED
#define FSCTL_OPLOCK_BREAK_ACK_NO_2                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 20,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_INVALIDATE_VOLUMES                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 21,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_FAT_BPB                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 22,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REQUEST_FILTER_OPLOCK                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 23,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_FILESYSTEM_GET_STATISTICS                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 24,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_NTFS_VOLUME_DATA                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 25,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_NTFS_FILE_RECORD                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 26,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_VOLUME_BITMAP                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_GET_RETRIEVAL_POINTERS                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 28,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_MOVE_FILE                                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 29,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_IS_VOLUME_DIRTY                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 30,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_ALLOW_EXTENDED_DASD_IO                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 32,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_FIND_FILES_BY_SID                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 35,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_SET_OBJECT_ID                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 38,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_GET_OBJECT_ID                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 39,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DELETE_OBJECT_ID                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 40,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_SET_REPARSE_POINT                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 41,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_GET_REPARSE_POINT                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 42,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DELETE_REPARSE_POINT                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 43,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_ENUM_USN_DATA                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 44,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_SECURITY_ID_CHECK                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 45,  METHOD_NEITHER,    FILE_READ_DATA)
#define FSCTL_READ_USN_JOURNAL                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 46,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_SET_OBJECT_ID_EXTENDED                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 47,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_CREATE_OR_GET_OBJECT_ID                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 48,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_SPARSE                                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 49,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_SET_ZERO_DATA                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 50,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_QUERY_ALLOCATED_RANGES                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 51,  METHOD_NEITHER,    FILE_READ_DATA)
#define FSCTL_ENABLE_UPGRADE                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 52,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_SET_ENCRYPTION                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 53,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_ENCRYPTION_FSCTL_IO                              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 54,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_WRITE_RAW_ENCRYPTED                              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 55,  METHOD_NEITHER,    FILE_SPECIAL_ACCESS)
#define FSCTL_READ_RAW_ENCRYPTED                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 56,  METHOD_NEITHER,    FILE_SPECIAL_ACCESS)
#define FSCTL_CREATE_USN_JOURNAL                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 57,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_READ_FILE_USN_DATA                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 58,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_WRITE_USN_CLOSE_RECORD                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_EXTEND_VOLUME                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 60,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_USN_JOURNAL                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 61,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DELETE_USN_JOURNAL                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 62,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_MARK_HANDLE                                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 63,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SIS_COPYFILE                                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 64,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SIS_LINK_FILES                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65,  METHOD_BUFFERED,   FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_RECALL_FILE                                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 69,  METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_READ_FROM_PLEX                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 71,  METHOD_OUT_DIRECT, FILE_READ_DATA)
#define FSCTL_FILE_PREFETCH                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 72,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_MAKE_MEDIA_COMPATIBLE                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 76,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_SET_DEFECT_MANAGEMENT                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 77,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_QUERY_SPARING_INFO                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 78,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_ON_DISK_VOLUME_INFO                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 79,  METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_VOLUME_COMPRESSION_STATE                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 80,  METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_TXFS_MODIFY_RM                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 81,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_QUERY_RM_INFORMATION                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 82,  METHOD_BUFFERED,   FILE_READ_DATA)
#define FSCTL_TXFS_ROLLFORWARD_REDO                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 84,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_ROLLFORWARD_UNDO                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 85,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_START_RM                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 86,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_SHUTDOWN_RM                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 87,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_READ_BACKUP_INFORMATION                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 88,  METHOD_BUFFERED,   FILE_READ_DATA)
#define FSCTL_TXFS_WRITE_BACKUP_INFORMATION                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 89,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_CREATE_SECONDARY_RM                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 90,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_GET_METADATA_INFO                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 91,  METHOD_BUFFERED,   FILE_READ_DATA)
#define FSCTL_TXFS_GET_TRANSACTED_VERSION                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 92,  METHOD_BUFFERED,   FILE_READ_DATA)
#define FSCTL_TXFS_SAVEPOINT_INFORMATION                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 94,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_CREATE_MINIVERSION                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 95,  METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_TXFS_TRANSACTION_ACTIVE                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 99,  METHOD_BUFFERED,   FILE_READ_DATA)
#define FSCTL_SET_ZERO_ON_DEALLOCATION                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 101, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_SET_REPAIR                                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 102, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_REPAIR                                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 103, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_WAIT_FOR_REPAIR                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 104, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_INITIATE_REPAIR                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 106, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSC_INTERNAL                                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 107, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_SHRINK_VOLUME                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 108, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_SET_SHORT_NAME_BEHAVIOR                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 109, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DFSR_SET_GHOST_HANDLE_STATE                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 110, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 120, METHOD_BUFFERED,   FILE_READ_DATA)
#define FSCTL_TXFS_LIST_TRANSACTIONS                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 121, METHOD_BUFFERED,   FILE_READ_DATA)
#define FSCTL_QUERY_PAGEFILE_ENCRYPTION                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 122, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_RESET_VOLUME_ALLOCATION_HINTS                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 123, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_DEPENDENT_VOLUME                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 124, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SD_GLOBAL_CHANGE                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 125, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_TXFS_READ_BACKUP_INFORMATION2                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 126, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_LOOKUP_STREAM_FROM_CLUSTER                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 127, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_TXFS_WRITE_BACKUP_INFORMATION2                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 128, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_FILE_TYPE_NOTIFICATION                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 129, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_FILE_LEVEL_TRIM                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 130, METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_GET_BOOT_AREA_INFO                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 140, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_RETRIEVAL_POINTER_BASE                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 141, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_PERSISTENT_VOLUME_STATE                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 142, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_PERSISTENT_VOLUME_STATE                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 143, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REQUEST_OPLOCK                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 144, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_TUNNEL_REQUEST                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 145, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_IS_CSV_FILE                                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 146, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_FILE_SYSTEM_RECOGNITION                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 147, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_GET_VOLUME_PATH_NAME                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 148, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_GET_VOLUME_NAME_FOR_VOLUME_MOUNT_POINT       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 149, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_GET_VOLUME_PATH_NAMES_FOR_VOLUME_NAME        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 150, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_IS_FILE_ON_CSV_VOLUME                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 151, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CORRUPTION_HANDLING                              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 152, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_OFFLOAD_READ                                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 153, METHOD_BUFFERED,   FILE_READ_ACCESS)
#define FSCTL_OFFLOAD_WRITE                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 154, METHOD_BUFFERED,   FILE_WRITE_ACCESS)
#define FSCTL_CSV_INTERNAL                                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 155, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_PURGE_FAILURE_MODE                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 156, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_FILE_LAYOUT                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 157, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_IS_VOLUME_OWNED_BYCSVFS                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 158, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_INTEGRITY_INFORMATION                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 159, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_INTEGRITY_INFORMATION                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 160, METHOD_BUFFERED,   FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_QUERY_FILE_REGIONS                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 161, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_RKF_INTERNAL                                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 171, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_SCRUB_DATA                                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 172, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REPAIR_COPIES                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 173, METHOD_BUFFERED,   FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_DISABLE_LOCAL_BUFFERING                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 174, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_MGMT_LOCK                                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 175, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_QUERY_DOWN_LEVEL_FILE_SYSTEM_CHARACTERISTICS CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 176, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_ADVANCE_FILE_ID                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 177, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_SYNC_TUNNEL_REQUEST                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 178, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_QUERY_VETO_FILE_DIRECT_IO                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 179, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_WRITE_USN_REASON                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 180, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_CONTROL                                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 181, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_REFS_VOLUME_DATA                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 182, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CSV_H_BREAKING_SYNC_TUNNEL_REQUEST               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 185, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_STORAGE_CLASSES                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 187, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_REGION_INFO                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 188, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_USN_TRACK_MODIFIED_RANGES                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 189, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_SHARED_VIRTUAL_DISK_SUPPORT                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 192, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SVHDX_SYNC_TUNNEL_REQUEST                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 193, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SVHDX_SET_INITIATOR_INFORMATION                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 194, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_EXTERNAL_BACKING                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 195, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_GET_EXTERNAL_BACKING                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 196, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DELETE_EXTERNAL_BACKING                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 197, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_ENUM_EXTERNAL_BACKING                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 198, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_ENUM_OVERLAY                                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 199, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_ADD_OVERLAY                                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 204, METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_REMOVE_OVERLAY                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 205, METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_UPDATE_OVERLAY                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 206, METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_SHUFFLE_FILE                                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 208, METHOD_BUFFERED,   FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FSCTL_DUPLICATE_EXTENTS_TO_FILE                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 209, METHOD_BUFFERED,   FILE_WRITE_DATA )
#define FSCTL_SPARSE_OVERALLOCATE                              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 211, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_STORAGE_QOS_CONTROL                              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 212, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_INITIATE_FILE_METADATA_OPTIMIZATION              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 215, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_QUERY_FILE_METADATA_OPTIMIZATION                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 216, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_SVHDX_ASYNC_TUNNEL_REQUEST                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 217, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_WOF_VERSION                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 218, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_HCS_SYNC_TUNNEL_REQUEST                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 219, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_HCS_ASYNC_TUNNEL_REQUEST                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 220, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_EXTENT_READ_CACHE_INFO                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 221, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_QUERY_REFS_VOLUME_COUNTER_INFO                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 222, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_CLEAN_VOLUME_METADATA                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 223, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_INTEGRITY_INFORMATION_EX                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 224, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SUSPEND_OVERLAY                                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 225, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_VIRTUAL_STORAGE_QUERY_PROPERTY                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 226, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_FILESYSTEM_GET_STATISTICS_EX                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 227, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_VOLUME_CONTAINER_STATE                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 228, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_LAYER_ROOT                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 229, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_DIRECT_ACCESS_EXTENTS                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 230, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_NOTIFY_STORAGE_SPACE_ALLOCATION                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 231, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SSDI_STORAGE_REQUEST                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 232, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_DIRECT_IMAGE_ORIGINAL_BASE                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 233, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_READ_UNPRIVILEGED_USN_JOURNAL                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 234, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_GHOST_FILE_EXTENTS                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 235, METHOD_BUFFERED,   FILE_WRITE_ACCESS)
#define FSCTL_QUERY_GHOSTED_FILE_EXTENTS                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 236, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_UNMAP_SPACE                                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 237, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_HCS_SYNC_NO_WRITE_TUNNEL_REQUEST                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 238, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_START_VIRTUALIZATION_INSTANCE                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 240, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_FILTER_FILE_IDENTIFIER                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 241, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_STREAMS_QUERY_PARAMETERS                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 241, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_STREAMS_ASSOCIATE_ID                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 242, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_STREAMS_QUERY_ID                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 243, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_RETRIEVAL_POINTERS_AND_REFCOUNT              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 244, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_QUERY_VOLUME_NUMA_INFO                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 245, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_DEALLOCATE_RANGES                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 246, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_REFS_SMR_VOLUME_INFO                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 247, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 248, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_REFS_FILE_STRICTLY_SEQUENTIAL                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 249, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DUPLICATE_EXTENTS_TO_FILE_EX                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 250, METHOD_BUFFERED,   FILE_WRITE_DATA)
#define FSCTL_QUERY_BAD_RANGES                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 251, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_DAX_ALLOC_ALIGNMENT_HINT                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 252, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DELETE_CORRUPTED_REFS_CONTAINER                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 253, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SCRUB_UNDISCOVERABLE_ID                          CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 254, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_NOTIFY_DATA_CHANGE                               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 255, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_START_VIRTUALIZATION_INSTANCE_EX                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 256, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_ENCRYPTION_KEY_CONTROL                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 257, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_VIRTUAL_STORAGE_SET_BEHAVIOR                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 258, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_REPARSE_POINT_EX                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 259, METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define FSCTL_REARRANGE_FILE                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 264, METHOD_BUFFERED,   FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FSCTL_VIRTUAL_STORAGE_PASSTHROUGH                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 265, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_GET_RETRIEVAL_POINTER_COUNT                      CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 266, METHOD_NEITHER,    FILE_ANY_ACCESS)
#define FSCTL_ENABLE_PER_IO_FLAGS                              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 267, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_ASYNC_DUPLICATE_EXTENTS_STATUS             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 268, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SMB_SHARE_FLUSH_AND_PURGE                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 271, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_STREAM_SNAPSHOT_MANAGEMENT                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 272, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_MANAGE_BYPASS_IO                                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 274, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_DEALLOCATE_RANGES_EX                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 275, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_SET_CACHED_RUNS_STATE                            CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 276, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_SET_VOLUME_COMPRESSION_INFO                 CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 277, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_QUERY_VOLUME_COMPRESSION_INFO               CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 278, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_DUPLICATE_CLUSTER                                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 279, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CREATE_LCN_WEAK_REFERENCE                        CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 280, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CLEAR_LCN_WEAK_REFERENCE                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 281, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_QUERY_LCN_WEAK_REFERENCE                         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 282, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CLEAR_ALL_LCN_WEAK_REFERENCES                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 283, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_SET_VOLUME_DEDUP_INFO                       CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 284, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_QUERY_VOLUME_DEDUP_INFO                     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 285, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_LMR_QUERY_INFO                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 286, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_CHECKPOINT_VOLUME                           CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 287, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_QUERY_VOLUME_TOTAL_SHARED_LCNS              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 288, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_UPGRADE_VOLUME                                   CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 289, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_SET_VOLUME_IO_METRICS_INFO                  CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 290, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_QUERY_VOLUME_IO_METRICS_INFO                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 291, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_SET_ROLLBACK_PROTECTION_INFO                CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 292, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_REFS_QUERY_ROLLBACK_PROTECTION_INFO              CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 293, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_FILE_SOV_CHECK_RANGE                             CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 294, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define FSCTL_CASCADES_REFS_SET_FILE_REMOTE                    CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 295, METHOD_BUFFERED,   FILE_ANY_ACCESS)
#define IOCTL_AVIO_ALLOCATE_STREAM                             CTL_CODE(FILE_DEVICE_AVIO,        1,   METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define IOCTL_AVIO_FREE_STREAM                                 CTL_CODE(FILE_DEVICE_AVIO,        2,   METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)
#define IOCTL_AVIO_MODIFY_STREAM                               CTL_CODE(FILE_DEVICE_AVIO,        3,   METHOD_BUFFERED,   FILE_SPECIAL_ACCESS)

  typedef struct _PATHNAME_BUFFER
  {
    DWORD PathNameLength;
    WCHAR Name[1];
  } PATHNAME_BUFFER, *PPATHNAME_BUFFER;

  typedef struct _FSCTL_QUERY_FAT_BPB_BUFFER
  {
    BYTE First0x24BytesOfBootSector[0x24];
  } FSCTL_QUERY_FAT_BPB_BUFFER, *PFSCTL_QUERY_FAT_BPB_BUFFER;

  typedef struct
  {
    LARGE_INTEGER VolumeSerialNumber;
    LARGE_INTEGER NumberSectors;
    LARGE_INTEGER TotalClusters;
    LARGE_INTEGER FreeClusters;
    LARGE_INTEGER TotalReserved;
    DWORD         BytesPerSector;
    DWORD         BytesPerCluster;
    DWORD         BytesPerFileRecordSegment;
    DWORD         ClustersPerFileRecordSegment;
    LARGE_INTEGER MftValidDataLength;
    LARGE_INTEGER MftStartLcn;
    LARGE_INTEGER Mft2StartLcn;
    LARGE_INTEGER MftZoneStart;
    LARGE_INTEGER MftZoneEnd;
  } NTFS_VOLUME_DATA_BUFFER, *PNTFS_VOLUME_DATA_BUFFER;

  typedef struct
  {
    DWORD ByteCount;
    WORD  MajorVersion;
    WORD  MinorVersion;
    DWORD BytesPerPhysicalSector;
    WORD  LfsMajorVersion;
    WORD  LfsMinorVersion;
    DWORD MaxDeviceTrimExtentCount;
    DWORD MaxDeviceTrimByteCount;
    DWORD MaxVolumeTrimExtentCount;
    DWORD MaxVolumeTrimByteCount;
  } NTFS_EXTENDED_VOLUME_DATA, *PNTFS_EXTENDED_VOLUME_DATA;

  typedef struct
  {
    DWORD         ByteCount;
    DWORD         MajorVersion;
    DWORD         MinorVersion;
    DWORD         BytesPerPhysicalSector;
    LARGE_INTEGER VolumeSerialNumber;
    LARGE_INTEGER NumberSectors;
    LARGE_INTEGER TotalClusters;
    LARGE_INTEGER FreeClusters;
    LARGE_INTEGER TotalReserved;
    DWORD         BytesPerSector;
    DWORD         BytesPerCluster;
    LARGE_INTEGER MaximumSizeOfResidentFile;
    WORD          FastTierDataFillRatio;
    WORD          SlowTierDataFillRatio;
    DWORD         DestagesFastTierToSlowTierRate;
    WORD          MetadataChecksumType;
    BYTE          Reserved0[6];
    DWORD         DriverMajorVersion;
    DWORD         DriverMinorVersion;
    LARGE_INTEGER Reserved[7];
  } REFS_VOLUME_DATA_BUFFER, *PREFS_VOLUME_DATA_BUFFER;

#define REFS_VOLUME_DATA_BUFFER_CONTAINS_DRIVER_VERSION(VOLUME_DATA_BUFFER) \
  ((VOLUME_DATA_BUFFER)->ByteCount >= RTL_SIZEOF_THROUGH_FIELD(REFS_VOLUME_DATA_BUFFER, DriverMinorVersion))

  typedef struct
  {
    LARGE_INTEGER StartingLcn;
  } STARTING_LCN_INPUT_BUFFER, *PSTARTING_LCN_INPUT_BUFFER;

#define GET_VOLUME_BITMAP_FLAG_MASK_METADATA 0x00000001

  typedef struct
  {
    LARGE_INTEGER StartingLcn;
    DWORD         Flags;
  } STARTING_LCN_INPUT_BUFFER_EX, *PSTARTING_LCN_INPUT_BUFFER_EX;

  typedef struct
  {
    LARGE_INTEGER StartingLcn;
    LARGE_INTEGER BitmapSize;
    BYTE          Buffer[1];
  } VOLUME_BITMAP_BUFFER, *PVOLUME_BITMAP_BUFFER;

  typedef struct
  {
    LARGE_INTEGER StartingVcn;
  } STARTING_VCN_INPUT_BUFFER, *PSTARTING_VCN_INPUT_BUFFER;

  typedef struct RETRIEVAL_POINTERS_BUFFER
  {
    DWORD         ExtentCount;
    LARGE_INTEGER StartingVcn;
    struct
    {
      LARGE_INTEGER NextVcn;
      LARGE_INTEGER Lcn;
    } Extents[1];
  } RETRIEVAL_POINTERS_BUFFER, *PRETRIEVAL_POINTERS_BUFFER;

  typedef struct RETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER
  {
    DWORD         ExtentCount;
    LARGE_INTEGER StartingVcn;
    struct
    {
      LARGE_INTEGER NextVcn;
      LARGE_INTEGER Lcn;
      DWORD         ReferenceCount;
    } Extents[1];
  } RETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER, *PRETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER;

  typedef struct RETRIEVAL_POINTER_COUNT
  {
    DWORD ExtentCount;
  } RETRIEVAL_POINTER_COUNT, *PRETRIEVAL_POINTER_COUNT;

  typedef struct
  {
    LARGE_INTEGER FileReferenceNumber;
  } NTFS_FILE_RECORD_INPUT_BUFFER, *PNTFS_FILE_RECORD_INPUT_BUFFER;

  typedef struct
  {
    LARGE_INTEGER FileReferenceNumber;
    DWORD         FileRecordLength;
    BYTE          FileRecordBuffer[1];
  } NTFS_FILE_RECORD_OUTPUT_BUFFER, *PNTFS_FILE_RECORD_OUTPUT_BUFFER;

  typedef struct
  {
    HANDLE        FileHandle;
    LARGE_INTEGER StartingVcn;
    LARGE_INTEGER StartingLcn;
    DWORD         ClusterCount;
  } MOVE_FILE_DATA, *PMOVE_FILE_DATA;

  typedef struct _MOVE_FILE_RECORD_DATA
  {
    HANDLE        FileHandle;
    LARGE_INTEGER SourceFileRecord;
    LARGE_INTEGER TargetFileRecord;
  } MOVE_FILE_RECORD_DATA, *PMOVE_FILE_RECORD_DATA;

  typedef struct _MOVE_FILE_DATA32
  {
    UINT32        FileHandle;
    LARGE_INTEGER StartingVcn;
    LARGE_INTEGER StartingLcn;
    DWORD         ClusterCount;
  } MOVE_FILE_DATA32, *PMOVE_FILE_DATA32;

  typedef struct
  {
    DWORD Restart;
    SID   Sid;
  } FIND_BY_SID_DATA, *PFIND_BY_SID_DATA;

  typedef struct
  {
    DWORD NextEntryOffset;
    DWORD FileIndex;
    DWORD FileNameLength;
    WCHAR FileName[1];
  } FIND_BY_SID_OUTPUT, *PFIND_BY_SID_OUTPUT;

  typedef struct
  {
    DWORDLONG StartFileReferenceNumber;
    USN       LowUsn;
    USN       HighUsn;
  } MFT_ENUM_DATA_V0, *PMFT_ENUM_DATA_V0;

  typedef struct
  {
    DWORDLONG StartFileReferenceNumber;
    USN       LowUsn;
    USN       HighUsn;
    WORD      MinMajorVersion;
    WORD      MaxMajorVersion;
  } MFT_ENUM_DATA_V1, *PMFT_ENUM_DATA_V1;

  typedef MFT_ENUM_DATA_V1 MFT_ENUM_DATA, *PMFT_ENUM_DATA;

  typedef struct
  {
    DWORDLONG MaximumSize;
    DWORDLONG AllocationDelta;
  } CREATE_USN_JOURNAL_DATA, *PCREATE_USN_JOURNAL_DATA;

  typedef struct
  {
    WORD MinMajorVersion;
    WORD MaxMajorVersion;
  } READ_FILE_USN_DATA, *PREAD_FILE_USN_DATA;

  typedef struct
  {
    USN       StartUsn;
    DWORD     ReasonMask;
    DWORD     ReturnOnlyOnClose;
    DWORDLONG Timeout;
    DWORDLONG BytesToWaitFor;
    DWORDLONG UsnJournalID;
  } READ_USN_JOURNAL_DATA_V0, *PREAD_USN_JOURNAL_DATA_V0;

  typedef struct
  {
    USN       StartUsn;
    DWORD     ReasonMask;
    DWORD     ReturnOnlyOnClose;
    DWORDLONG Timeout;
    DWORDLONG BytesToWaitFor;
    DWORDLONG UsnJournalID;
    WORD      MinMajorVersion;
    WORD      MaxMajorVersion;
  } READ_USN_JOURNAL_DATA_V1, *PREAD_USN_JOURNAL_DATA_V1;

  typedef READ_USN_JOURNAL_DATA_V1 READ_USN_JOURNAL_DATA, *PREAD_USN_JOURNAL_DATA;

  typedef struct
  {
    DWORD     Flags;
    DWORD     Unused;
    DWORDLONG ChunkSize;
    LONGLONG  FileSizeThreshold;
  } USN_TRACK_MODIFIED_RANGES, *PUSN_TRACK_MODIFIED_RANGES;

  typedef struct
  {
    USN Usn;
  } USN_RANGE_TRACK_OUTPUT, *PUSN_RANGE_TRACK_OUTPUT;

#define FLAG_USN_TRACK_MODIFIED_RANGES_ENABLE 0x00000001

  typedef struct
  {
    DWORD         RecordLength;
    WORD          MajorVersion;
    WORD          MinorVersion;
    DWORDLONG     FileReferenceNumber;
    DWORDLONG     ParentFileReferenceNumber;
    USN           Usn;
    LARGE_INTEGER TimeStamp;
    DWORD         Reason;
    DWORD         SourceInfo;
    DWORD         SecurityId;
    DWORD         FileAttributes;
    WORD          FileNameLength;
    WORD          FileNameOffset;
    WCHAR         FileName[1];
  } USN_RECORD_V2, *PUSN_RECORD_V2;

  typedef struct
  {
    DWORD         RecordLength;
    WORD          MajorVersion;
    WORD          MinorVersion;
    FILE_ID_128   FileReferenceNumber;
    FILE_ID_128   ParentFileReferenceNumber;
    USN           Usn;
    LARGE_INTEGER TimeStamp;
    DWORD         Reason;
    DWORD         SourceInfo;
    DWORD         SecurityId;
    DWORD         FileAttributes;
    WORD          FileNameLength;
    WORD          FileNameOffset;
    WCHAR         FileName[1];
  } USN_RECORD_V3, *PUSN_RECORD_V3;

  typedef USN_RECORD_V2 USN_RECORD, *PUSN_RECORD;

  typedef struct
  {
    DWORD RecordLength;
    WORD  MajorVersion;
    WORD  MinorVersion;
  } USN_RECORD_COMMON_HEADER, *PUSN_RECORD_COMMON_HEADER;

  typedef struct
  {
    LONGLONG Offset;
    LONGLONG Length;
  } USN_RECORD_EXTENT, *PUSN_RECORD_EXTENT;

  typedef struct
  {
    USN_RECORD_COMMON_HEADER Header;
    FILE_ID_128              FileReferenceNumber;
    FILE_ID_128              ParentFileReferenceNumber;
    USN                      Usn;
    DWORD                    Reason;
    DWORD                    SourceInfo;
    DWORD                    RemainingExtents;
    WORD                     NumberOfExtents;
    WORD                     ExtentSize;
    USN_RECORD_EXTENT        Extents[1];
  } USN_RECORD_V4, *PUSN_RECORD_V4;

  typedef union
  {
    USN_RECORD_COMMON_HEADER Header;
    USN_RECORD_V2            V2;
    USN_RECORD_V3            V3;
    USN_RECORD_V4            V4;
  } USN_RECORD_UNION, *PUSN_RECORD_UNION;

#define USN_PAGE_SIZE                           (0x1000)
#define USN_REASON_DATA_OVERWRITE               (0x00000001)
#define USN_REASON_DATA_EXTEND                  (0x00000002)
#define USN_REASON_DATA_TRUNCATION              (0x00000004)
#define USN_REASON_NAMED_DATA_OVERWRITE         (0x00000010)
#define USN_REASON_NAMED_DATA_EXTEND            (0x00000020)
#define USN_REASON_NAMED_DATA_TRUNCATION        (0x00000040)
#define USN_REASON_FILE_CREATE                  (0x00000100)
#define USN_REASON_FILE_DELETE                  (0x00000200)
#define USN_REASON_EA_CHANGE                    (0x00000400)
#define USN_REASON_SECURITY_CHANGE              (0x00000800)
#define USN_REASON_RENAME_OLD_NAME              (0x00001000)
#define USN_REASON_RENAME_NEW_NAME              (0x00002000)
#define USN_REASON_INDEXABLE_CHANGE             (0x00004000)
#define USN_REASON_BASIC_INFO_CHANGE            (0x00008000)
#define USN_REASON_HARD_LINK_CHANGE             (0x00010000)
#define USN_REASON_COMPRESSION_CHANGE           (0x00020000)
#define USN_REASON_ENCRYPTION_CHANGE            (0x00040000)
#define USN_REASON_OBJECT_ID_CHANGE             (0x00080000)
#define USN_REASON_REPARSE_POINT_CHANGE         (0x00100000)
#define USN_REASON_STREAM_CHANGE                (0x00200000)
#define USN_REASON_TRANSACTED_CHANGE            (0x00400000)
#define USN_REASON_INTEGRITY_CHANGE             (0x00800000)
#define USN_REASON_DESIRED_STORAGE_CLASS_CHANGE (0x01000000)
#define USN_REASON_CLOSE                        (0x80000000)

  typedef struct
  {
    DWORDLONG UsnJournalID;
    USN       FirstUsn;
    USN       NextUsn;
    USN       LowestValidUsn;
    USN       MaxUsn;
    DWORDLONG MaximumSize;
    DWORDLONG AllocationDelta;
  } USN_JOURNAL_DATA_V0, *PUSN_JOURNAL_DATA_V0;

  typedef struct
  {
    DWORDLONG UsnJournalID;
    USN       FirstUsn;
    USN       NextUsn;
    USN       LowestValidUsn;
    USN       MaxUsn;
    DWORDLONG MaximumSize;
    DWORDLONG AllocationDelta;
    WORD      MinSupportedMajorVersion;
    WORD      MaxSupportedMajorVersion;
  } USN_JOURNAL_DATA_V1, *PUSN_JOURNAL_DATA_V1;

  typedef struct
  {
    DWORDLONG UsnJournalID;
    USN       FirstUsn;
    USN       NextUsn;
    USN       LowestValidUsn;
    USN       MaxUsn;
    DWORDLONG MaximumSize;
    DWORDLONG AllocationDelta;
    WORD      MinSupportedMajorVersion;
    WORD      MaxSupportedMajorVersion;
    DWORD     Flags;
    DWORDLONG RangeTrackChunkSize;
    LONGLONG  RangeTrackFileSizeThreshold;
  } USN_JOURNAL_DATA_V2, *PUSN_JOURNAL_DATA_V2;

  typedef USN_JOURNAL_DATA_V1 USN_JOURNAL_DATA, *PUSN_JOURNAL_DATA;

  typedef struct
  {
    DWORDLONG UsnJournalID;
    DWORD     DeleteFlags;
  } DELETE_USN_JOURNAL_DATA, *PDELETE_USN_JOURNAL_DATA;

#define USN_DELETE_FLAG_DELETE (0x00000001)
#define USN_DELETE_FLAG_NOTIFY (0x00000002)
#define USN_DELETE_VALID_FLAGS (0x00000003)

  typedef struct
  {
    __C89_NAMELESS union
    {
      DWORD UsnSourceInfo;
      DWORD CopyNumber;
    } DUMMYUNIONNAME;
    HANDLE VolumeHandle;
    DWORD  HandleInfo;
  } MARK_HANDLE_INFO, *PMARK_HANDLE_INFO;

  typedef struct
  {
    __C89_NAMELESS union
    {
      DWORD UsnSourceInfo;
      DWORD CopyNumber;
    } DUMMYUNIONNAME;
    UINT32 VolumeHandle;
    DWORD  HandleInfo;
  } MARK_HANDLE_INFO32, *PMARK_HANDLE_INFO32;

#define USN_SOURCE_DATA_MANAGEMENT               (0x00000001)
#define USN_SOURCE_AUXILIARY_DATA                (0x00000002)
#define USN_SOURCE_REPLICATION_MANAGEMENT        (0x00000004)
#define USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT (0x00000008)
#define USN_SOURCE_VALID_FLAGS \
  (USN_SOURCE_DATA_MANAGEMENT | USN_SOURCE_AUXILIARY_DATA | USN_SOURCE_REPLICATION_MANAGEMENT | USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT)

#define MARK_HANDLE_PROTECT_CLUSTERS                    (0x00000001)
#define MARK_HANDLE_TXF_SYSTEM_LOG                      (0x00000004)
#define MARK_HANDLE_NOT_TXF_SYSTEM_LOG                  (0x00000008)
#define MARK_HANDLE_REALTIME                            (0x00000020)
#define MARK_HANDLE_NOT_REALTIME                        (0x00000040)
#define MARK_HANDLE_CLOUD_SYNC                          (0x00000800)
#define MARK_HANDLE_READ_COPY                           (0x00000080)
#define MARK_HANDLE_NOT_READ_COPY                       (0x00000100)
#define MARK_HANDLE_FILTER_METADATA                     (0x00000200)
#define MARK_HANDLE_RETURN_PURGE_FAILURE                (0x00000400)
#define MARK_HANDLE_DISABLE_FILE_METADATA_OPTIMIZATION  (0x00001000)
#define MARK_HANDLE_ENABLE_USN_SOURCE_ON_PAGING_IO      (0x00002000)
#define MARK_HANDLE_SKIP_COHERENCY_SYNC_DISALLOW_WRITES (0x00004000)
#define MARK_HANDLE_SUPPRESS_VOLUME_OPEN_FLUSH          (0x00008000)
#define MARK_HANDLE_ENABLE_CPU_CACHE                    (0x10000000)

  typedef struct
  {
    ACCESS_MASK DesiredAccess;
    DWORD       SecurityIds[1];
  } BULK_SECURITY_TEST_DATA, *PBULK_SECURITY_TEST_DATA;

#define VOLUME_IS_DIRTY          (0x00000001)
#define VOLUME_UPGRADE_SCHEDULED (0x00000002)
#define VOLUME_SESSION_OPEN      (0x00000004)

  typedef struct _FILE_PREFETCH
  {
    DWORD     Type;
    DWORD     Count;
    DWORDLONG Prefetch[1];
  } FILE_PREFETCH, *PFILE_PREFETCH;

  typedef struct _FILE_PREFETCH_EX
  {
    DWORD     Type;
    DWORD     Count;
    PVOID     Context;
    DWORDLONG Prefetch[1];
  } FILE_PREFETCH_EX, *PFILE_PREFETCH_EX;

#define FILE_PREFETCH_TYPE_FOR_CREATE     0x1
#define FILE_PREFETCH_TYPE_FOR_DIRENUM    0x2
#define FILE_PREFETCH_TYPE_FOR_CREATE_EX  0x3
#define FILE_PREFETCH_TYPE_FOR_DIRENUM_EX 0x4
#define FILE_PREFETCH_TYPE_MAX            0x4

  typedef struct _FILESYSTEM_STATISTICS
  {
    WORD  FileSystemType;
    WORD  Version;
    DWORD SizeOfCompleteStructure;
    DWORD UserFileReads;
    DWORD UserFileReadBytes;
    DWORD UserDiskReads;
    DWORD UserFileWrites;
    DWORD UserFileWriteBytes;
    DWORD UserDiskWrites;
    DWORD MetaDataReads;
    DWORD MetaDataReadBytes;
    DWORD MetaDataDiskReads;
    DWORD MetaDataWrites;
    DWORD MetaDataWriteBytes;
    DWORD MetaDataDiskWrites;
  } FILESYSTEM_STATISTICS, *PFILESYSTEM_STATISTICS;

#define FILESYSTEM_STATISTICS_TYPE_NTFS  1
#define FILESYSTEM_STATISTICS_TYPE_FAT   2
#define FILESYSTEM_STATISTICS_TYPE_EXFAT 3
#define FILESYSTEM_STATISTICS_TYPE_REFS  4

  typedef struct _FAT_STATISTICS
  {
    DWORD CreateHits;
    DWORD SuccessfulCreates;
    DWORD FailedCreates;
    DWORD NonCachedReads;
    DWORD NonCachedReadBytes;
    DWORD NonCachedWrites;
    DWORD NonCachedWriteBytes;
    DWORD NonCachedDiskReads;
    DWORD NonCachedDiskWrites;
  } FAT_STATISTICS, *PFAT_STATISTICS;

  typedef struct _EXFAT_STATISTICS
  {
    DWORD CreateHits;
    DWORD SuccessfulCreates;
    DWORD FailedCreates;
    DWORD NonCachedReads;
    DWORD NonCachedReadBytes;
    DWORD NonCachedWrites;
    DWORD NonCachedWriteBytes;
    DWORD NonCachedDiskReads;
    DWORD NonCachedDiskWrites;
  } EXFAT_STATISTICS, *PEXFAT_STATISTICS;

  typedef struct _NTFS_STATISTICS
  {
    DWORD LogFileFullExceptions;
    DWORD OtherExceptions;
    DWORD MftReads;
    DWORD MftReadBytes;
    DWORD MftWrites;
    DWORD MftWriteBytes;
    struct
    {
      WORD Write;
      WORD Create;
      WORD SetInfo;
      WORD Flush;
    } MftWritesUserLevel;
    WORD  MftWritesFlushForLogFileFull;
    WORD  MftWritesLazyWriter;
    WORD  MftWritesUserRequest;
    DWORD Mft2Writes;
    DWORD Mft2WriteBytes;
    struct
    {
      WORD Write;
      WORD Create;
      WORD SetInfo;
      WORD Flush;
    } Mft2WritesUserLevel;
    WORD  Mft2WritesFlushForLogFileFull;
    WORD  Mft2WritesLazyWriter;
    WORD  Mft2WritesUserRequest;
    DWORD RootIndexReads;
    DWORD RootIndexReadBytes;
    DWORD RootIndexWrites;
    DWORD RootIndexWriteBytes;
    DWORD BitmapReads;
    DWORD BitmapReadBytes;
    DWORD BitmapWrites;
    DWORD BitmapWriteBytes;
    WORD  BitmapWritesFlushForLogFileFull;
    WORD  BitmapWritesLazyWriter;
    WORD  BitmapWritesUserRequest;
    struct
    {
      WORD Write;
      WORD Create;
      WORD SetInfo;
    } BitmapWritesUserLevel;
    DWORD MftBitmapReads;
    DWORD MftBitmapReadBytes;
    DWORD MftBitmapWrites;
    DWORD MftBitmapWriteBytes;
    WORD  MftBitmapWritesFlushForLogFileFull;
    WORD  MftBitmapWritesLazyWriter;
    WORD  MftBitmapWritesUserRequest;
    struct
    {
      WORD Write;
      WORD Create;
      WORD SetInfo;
      WORD Flush;
    } MftBitmapWritesUserLevel;
    DWORD UserIndexReads;
    DWORD UserIndexReadBytes;
    DWORD UserIndexWrites;
    DWORD UserIndexWriteBytes;
    DWORD LogFileReads;
    DWORD LogFileReadBytes;
    DWORD LogFileWrites;
    DWORD LogFileWriteBytes;
    struct
    {
      DWORD Calls;
      DWORD Clusters;
      DWORD Hints;
      DWORD RunsReturned;
      DWORD HintsHonored;
      DWORD HintsClusters;
      DWORD Cache;
      DWORD CacheClusters;
      DWORD CacheMiss;
      DWORD CacheMissClusters;
    } Allocate;
    DWORD DiskResourcesExhausted;
  } NTFS_STATISTICS, *PNTFS_STATISTICS;

  typedef struct _FILESYSTEM_STATISTICS_EX
  {
    WORD      FileSystemType;
    WORD      Version;
    DWORD     SizeOfCompleteStructure;
    DWORDLONG UserFileReads;
    DWORDLONG UserFileReadBytes;
    DWORDLONG UserDiskReads;
    DWORDLONG UserFileWrites;
    DWORDLONG UserFileWriteBytes;
    DWORDLONG UserDiskWrites;
    DWORDLONG MetaDataReads;
    DWORDLONG MetaDataReadBytes;
    DWORDLONG MetaDataDiskReads;
    DWORDLONG MetaDataWrites;
    DWORDLONG MetaDataWriteBytes;
    DWORDLONG MetaDataDiskWrites;
  } FILESYSTEM_STATISTICS_EX, *PFILESYSTEM_STATISTICS_EX;

  typedef struct _NTFS_STATISTICS_EX
  {
    DWORD     LogFileFullExceptions;
    DWORD     OtherExceptions;
    DWORDLONG MftReads;
    DWORDLONG MftReadBytes;
    DWORDLONG MftWrites;
    DWORDLONG MftWriteBytes;
    struct
    {
      DWORD Write;
      DWORD Create;
      DWORD SetInfo;
      DWORD Flush;
    } MftWritesUserLevel;
    DWORD     MftWritesFlushForLogFileFull;
    DWORD     MftWritesLazyWriter;
    DWORD     MftWritesUserRequest;
    DWORDLONG Mft2Writes;
    DWORDLONG Mft2WriteBytes;
    struct
    {
      DWORD Write;
      DWORD Create;
      DWORD SetInfo;
      DWORD Flush;
    } Mft2WritesUserLevel;
    DWORD     Mft2WritesFlushForLogFileFull;
    DWORD     Mft2WritesLazyWriter;
    DWORD     Mft2WritesUserRequest;
    DWORDLONG RootIndexReads;
    DWORDLONG RootIndexReadBytes;
    DWORDLONG RootIndexWrites;
    DWORDLONG RootIndexWriteBytes;
    DWORDLONG BitmapReads;
    DWORDLONG BitmapReadBytes;
    DWORDLONG BitmapWrites;
    DWORDLONG BitmapWriteBytes;
    DWORD     BitmapWritesFlushForLogFileFull;
    DWORD     BitmapWritesLazyWriter;
    DWORD     BitmapWritesUserRequest;
    struct
    {
      DWORD Write;
      DWORD Create;
      DWORD SetInfo;
      DWORD Flush;
    } BitmapWritesUserLevel;
    DWORDLONG MftBitmapReads;
    DWORDLONG MftBitmapReadBytes;
    DWORDLONG MftBitmapWrites;
    DWORDLONG MftBitmapWriteBytes;
    DWORD     MftBitmapWritesFlushForLogFileFull;
    DWORD     MftBitmapWritesLazyWriter;
    DWORD     MftBitmapWritesUserRequest;
    struct
    {
      DWORD Write;
      DWORD Create;
      DWORD SetInfo;
      DWORD Flush;
    } MftBitmapWritesUserLevel;
    DWORDLONG UserIndexReads;
    DWORDLONG UserIndexReadBytes;
    DWORDLONG UserIndexWrites;
    DWORDLONG UserIndexWriteBytes;
    DWORDLONG LogFileReads;
    DWORDLONG LogFileReadBytes;
    DWORDLONG LogFileWrites;
    DWORDLONG LogFileWriteBytes;
    struct
    {
      DWORD     Calls;
      DWORD     RunsReturned;
      DWORD     Hints;
      DWORD     HintsHonored;
      DWORD     Cache;
      DWORD     CacheMiss;
      DWORDLONG Clusters;
      DWORDLONG HintsClusters;
      DWORDLONG CacheClusters;
      DWORDLONG CacheMissClusters;
    } Allocate;
    DWORD     DiskResourcesExhausted;
    DWORDLONG VolumeTrimCount;
    DWORDLONG VolumeTrimTime;
    DWORDLONG VolumeTrimByteCount;
    DWORDLONG FileLevelTrimCount;
    DWORDLONG FileLevelTrimTime;
    DWORDLONG FileLevelTrimByteCount;
    DWORDLONG VolumeTrimSkippedCount;
    DWORDLONG VolumeTrimSkippedByteCount;
    DWORDLONG NtfsFillStatInfoFromMftRecordCalledCount;
    DWORDLONG NtfsFillStatInfoFromMftRecordBailedBecauseOfAttributeListCount;
    DWORDLONG NtfsFillStatInfoFromMftRecordBailedBecauseOfNonResReparsePointCount;
  } NTFS_STATISTICS_EX, *PNTFS_STATISTICS_EX;

  typedef struct _FILE_OBJECTID_BUFFER
  {
    BYTE ObjectId[16];
    __C89_NAMELESS union
    {
      __C89_NAMELESS struct
      {
        BYTE BirthVolumeId[16];
        BYTE BirthObjectId[16];
        BYTE DomainId[16];
      } DUMMYSTRUCTNAME;
      BYTE ExtendedInfo[48];
    } DUMMYUNIONNAME;
  } FILE_OBJECTID_BUFFER, *PFILE_OBJECTID_BUFFER;

  typedef struct _FILE_SET_SPARSE_BUFFER
  {
    BOOLEAN SetSparse;
  } FILE_SET_SPARSE_BUFFER, *PFILE_SET_SPARSE_BUFFER;

  typedef struct _FILE_ZERO_DATA_INFORMATION
  {
    LARGE_INTEGER FileOffset;
    LARGE_INTEGER BeyondFinalZero;
  } FILE_ZERO_DATA_INFORMATION, *PFILE_ZERO_DATA_INFORMATION;

  typedef struct _FILE_ZERO_DATA_INFORMATION_EX
  {
    LARGE_INTEGER FileOffset;
    LARGE_INTEGER BeyondFinalZero;
    DWORD         Flags;
  } FILE_ZERO_DATA_INFORMATION_EX, *PFILE_ZERO_DATA_INFORMATION_EX;

#define FILE_ZERO_DATA_INFORMATION_FLAG_PRESERVE_CACHED_DATA (0x00000001)

  typedef struct _FILE_ALLOCATED_RANGE_BUFFER
  {
    LARGE_INTEGER FileOffset;
    LARGE_INTEGER Length;
  } FILE_ALLOCATED_RANGE_BUFFER, *PFILE_ALLOCATED_RANGE_BUFFER;

  typedef struct _ENCRYPTION_BUFFER
  {
    DWORD EncryptionOperation;
    BYTE  Private[1];
  } ENCRYPTION_BUFFER, *PENCRYPTION_BUFFER;

#define FILE_SET_ENCRYPTION      0x00000001
#define FILE_CLEAR_ENCRYPTION    0x00000002
#define STREAM_SET_ENCRYPTION    0x00000003
#define STREAM_CLEAR_ENCRYPTION  0x00000004
#define MAXIMUM_ENCRYPTION_VALUE 0x00000004

  typedef struct _DECRYPTION_STATUS_BUFFER
  {
    BOOLEAN NoEncryptedStreams;
  } DECRYPTION_STATUS_BUFFER, *PDECRYPTION_STATUS_BUFFER;

#define ENCRYPTION_FORMAT_DEFAULT (0x01)

  typedef struct _REQUEST_RAW_ENCRYPTED_DATA
  {
    LONGLONG FileOffset;
    DWORD    Length;
  } REQUEST_RAW_ENCRYPTED_DATA, *PREQUEST_RAW_ENCRYPTED_DATA;

  typedef struct _ENCRYPTED_DATA_INFO
  {
    DWORDLONG StartingFileOffset;
    DWORD     OutputBufferOffset;
    DWORD     BytesWithinFileSize;
    DWORD     BytesWithinValidDataLength;
    WORD      CompressionFormat;
    BYTE      DataUnitShift;
    BYTE      ChunkShift;
    BYTE      ClusterShift;
    BYTE      EncryptionFormat;
    WORD      NumberOfDataBlocks;
    DWORD     DataBlockSize[ANYSIZE_ARRAY];
  } ENCRYPTED_DATA_INFO, *PENCRYPTED_DATA_INFO;

#define ENCRYPTED_DATA_INFO_SPARSE_FILE    0x00000001
#define ENCRYPTED_DATA_INFO_SPARSE_DATA    0x00000002
#define ENCRYPTED_DATA_INFO_4K_SPARSE_UNIT 0x00000004

  typedef struct _EXTENDED_ENCRYPTED_DATA_INFO
  {
    DWORD ExtendedCode;
    DWORD Length;
    DWORD Flags;
    DWORD Reserved;
  } EXTENDED_ENCRYPTED_DATA_INFO, *PEXTENDED_ENCRYPTED_DATA_INFO;

  typedef struct _PLEX_READ_DATA_REQUEST
  {
    LARGE_INTEGER ByteOffset;
    DWORD         ByteLength;
    DWORD         PlexNumber;
  } PLEX_READ_DATA_REQUEST, *PPLEX_READ_DATA_REQUEST;

  typedef struct _SI_COPYFILE
  {
    DWORD SourceFileNameLength;
    DWORD DestinationFileNameLength;
    DWORD Flags;
    WCHAR FileNameBuffer[1];
  } SI_COPYFILE, *PSI_COPYFILE;

#define COPYFILE_SIS_LINK    0x0001
#define COPYFILE_SIS_REPLACE 0x0002
#define COPYFILE_SIS_FLAGS   0x0003

  typedef struct _FILE_MAKE_COMPATIBLE_BUFFER
  {
    BOOLEAN CloseDisc;
  } FILE_MAKE_COMPATIBLE_BUFFER, *PFILE_MAKE_COMPATIBLE_BUFFER;

  typedef struct _FILE_SET_DEFECT_MGMT_BUFFER
  {
    BOOLEAN Disable;
  } FILE_SET_DEFECT_MGMT_BUFFER, *PFILE_SET_DEFECT_MGMT_BUFFER;

  typedef struct _FILE_QUERY_SPARING_BUFFER
  {
    DWORD   SparingUnitBytes;
    BOOLEAN SoftwareSparing;
    DWORD   TotalSpareBlocks;
    DWORD   FreeSpareBlocks;
  } FILE_QUERY_SPARING_BUFFER, *PFILE_QUERY_SPARING_BUFFER;

  typedef struct _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER
  {
    LARGE_INTEGER DirectoryCount;
    LARGE_INTEGER FileCount;
    WORD          FsFormatMajVersion;
    WORD          FsFormatMinVersion;
    WCHAR         FsFormatName[12];
    LARGE_INTEGER FormatTime;
    LARGE_INTEGER LastUpdateTime;
    WCHAR         CopyrightInfo[34];
    WCHAR         AbstractInfo[34];
    WCHAR         FormattingImplementationInfo[34];
    WCHAR         LastModifyingImplementationInfo[34];
  } FILE_QUERY_ON_DISK_VOL_INFO_BUFFER, *PFILE_QUERY_ON_DISK_VOL_INFO_BUFFER;

#define SET_REPAIR_ENABLED                          (0x00000001)
#define SET_REPAIR_WARN_ABOUT_DATA_LOSS             (0x00000008)
#define SET_REPAIR_DISABLED_AND_BUGCHECK_ON_CORRUPT (0x00000010)
#define SET_REPAIR_VALID_MASK                       (0x00000019)

#define FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_IN_USE             (0x0000000000000001)
#define FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_REUSED                 (0x0000000000000002)
#define FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_EXIST              (0x0000000000000004)
#define FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_BASE_RECORD        (0x0000000000000008)
#define FILE_INITIATE_REPAIR_HINT1_SYSTEM_FILE                        (0x0000000000000010)
#define FILE_INITIATE_REPAIR_HINT1_NOT_IMPLEMENTED                    (0x0000000000000020)
#define FILE_INITIATE_REPAIR_HINT1_UNABLE_TO_REPAIR                   (0x0000000000000040)
#define FILE_INITIATE_REPAIR_HINT1_REPAIR_DISABLED                    (0x0000000000000080)
#define FILE_INITIATE_REPAIR_HINT1_RECURSIVELY_CORRUPTED              (0x0000000000000100)
#define FILE_INITIATE_REPAIR_HINT1_ORPHAN_GENERATED                   (0x0000000000000200)
#define FILE_INITIATE_REPAIR_HINT1_REPAIRED                           (0x0000000000000400)
#define FILE_INITIATE_REPAIR_HINT1_NOTHING_WRONG                      (0x0000000000000800)
#define FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_NOT_FOUND                (0x0000000000001000)
#define FILE_INITIATE_REPAIR_HINT1_POTENTIAL_CROSSLINK                (0x0000000000002000)
#define FILE_INITIATE_REPAIR_HINT1_STALE_INFORMATION                  (0x0000000000004000)
#define FILE_INITIATE_REPAIR_HINT1_CLUSTERS_ALREADY_IN_USE            (0x0000000000008000)
#define FILE_INITIATE_REPAIR_HINT1_LCN_NOT_EXIST                      (0x0000000000010000)
#define FILE_INITIATE_REPAIR_HINT1_INVALID_RUN_LENGTH                 (0x0000000000020000)
#define FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_ORPHAN             (0x0000000000040000)
#define FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_IS_BASE_RECORD         (0x0000000000080000)
#define FILE_INITIATE_REPAIR_HINT1_INVALID_ARRAY_LENGTH_COUNT         (0x0000000000100000)
#define FILE_INITIATE_REPAIR_HINT1_SID_VALID                          (0x0000000000200000)
#define FILE_INITIATE_REPAIR_HINT1_SID_MISMATCH                       (0x0000000000400000)
#define FILE_INITIATE_REPAIR_HINT1_INVALID_PARENT                     (0x0000000000800000)
#define FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_IN_USE      (0x0000000001000000)
#define FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_REUSED          (0x0000000002000000)
#define FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_EXIST       (0x0000000004000000)
#define FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_BASE_RECORD (0x0000000008000000)
#define FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_INDEX       (0x0000000010000000)
#define FILE_INITIATE_REPAIR_HINT1_VALID_INDEX_ENTRY                  (0x0000000020000000)
#define FILE_INITIATE_REPAIR_HINT1_OUT_OF_GENERIC_NAMES               (0x0000000040000000)
#define FILE_INITIATE_REPAIR_HINT1_OUT_OF_RESOURCE                    (0x0000000080000000)
#define FILE_INITIATE_REPAIR_HINT1_INVALID_LCN                        (0x0000000100000000)
#define FILE_INITIATE_REPAIR_HINT1_INVALID_VCN                        (0x0000000200000000)
#define FILE_INITIATE_REPAIR_HINT1_NAME_CONFLICT                      (0x0000000400000000)
#define FILE_INITIATE_REPAIR_HINT1_ORPHAN                             (0x0000000800000000)
#define FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_TOO_SMALL                (0x0000001000000000)
#define FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_NON_RESIDENT             (0x0000002000000000)
#define FILE_INITIATE_REPAIR_HINT1_DENY_DEFRAG                        (0x0000004000000000)
#define FILE_INITIATE_REPAIR_HINT1_PREVIOUS_PARENT_STILL_VALID        (0x0000008000000000)
#define FILE_INITIATE_REPAIR_HINT1_INDEX_ENTRY_MISMATCH               (0x0000010000000000)
#define FILE_INITIATE_REPAIR_HINT1_INVALID_ORPHAN_RECOVERY_NAME       (0x0000020000000000)
#define FILE_INITIATE_REPAIR_HINT1_MULTIPLE_FILE_NAME_ATTRIBUTES      (0x0000040000000000)

  typedef DWORDLONG CLSN;

  typedef struct _FILE_INITIATE_REPAIR_OUTPUT_BUFFER
  {
    DWORDLONG Hint1;
    DWORDLONG Hint2;
    CLSN      Clsn;
    DWORD     Status;
  } FILE_INITIATE_REPAIR_OUTPUT_BUFFER, *PFILE_INITIATE_REPAIR_OUTPUT_BUFFER;

  typedef enum _SHRINK_VOLUME_REQUEST_TYPES
  {
    ShrinkPrepare = 1,
    ShrinkCommit,
    ShrinkAbort
  } SHRINK_VOLUME_REQUEST_TYPES, *PSHRINK_VOLUME_REQUEST_TYPES;

  typedef struct _SHRINK_VOLUME_INFORMATION
  {
    SHRINK_VOLUME_REQUEST_TYPES ShrinkRequestType;
    DWORDLONG                   Flags;
    LONGLONG                    NewNumberOfSectors;
  } SHRINK_VOLUME_INFORMATION, *PSHRINK_VOLUME_INFORMATION;

#define TXFS_RM_FLAG_LOGGING_MODE                        0x00000001
#define TXFS_RM_FLAG_RENAME_RM                           0x00000002
#define TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX             0x00000004
#define TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN             0x00000008
#define TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS 0x00000010
#define TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT        0x00000020
#define TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE          0x00000040
#define TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX          0x00000080
#define TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN          0x00000100
#define TXFS_RM_FLAG_GROW_LOG                            0x00000400
#define TXFS_RM_FLAG_SHRINK_LOG                          0x00000800
#define TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE                0x00001000
#define TXFS_RM_FLAG_PRESERVE_CHANGES                    0x00002000
#define TXFS_RM_FLAG_RESET_RM_AT_NEXT_START              0x00004000
#define TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START       0x00008000
#define TXFS_RM_FLAG_PREFER_CONSISTENCY                  0x00010000
#define TXFS_RM_FLAG_PREFER_AVAILABILITY                 0x00020000

#define TXFS_LOGGING_MODE_SIMPLE (0x0001)
#define TXFS_LOGGING_MODE_FULL   (0x0002)

#define TXFS_TRANSACTION_STATE_NONE      0x00
#define TXFS_TRANSACTION_STATE_ACTIVE    0x01
#define TXFS_TRANSACTION_STATE_PREPARED  0x02
#define TXFS_TRANSACTION_STATE_NOTACTIVE 0x03

#define TXFS_MODIFY_RM_VALID_FLAGS                                                                                                         \
  (TXFS_RM_FLAG_LOGGING_MODE | TXFS_RM_FLAG_RENAME_RM | TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX | TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN |      \
  TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS | TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT | TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE | \
  TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX | TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN | TXFS_RM_FLAG_SHRINK_LOG | TXFS_RM_FLAG_GROW_LOG |    \
  TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE | TXFS_RM_FLAG_PRESERVE_CHANGES | TXFS_RM_FLAG_RESET_RM_AT_NEXT_START |                                \
  TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START | TXFS_RM_FLAG_PREFER_CONSISTENCY | TXFS_RM_FLAG_PREFER_AVAILABILITY)

  typedef struct _TXFS_MODIFY_RM
  {
    DWORD     Flags;
    DWORD     LogContainerCountMax;
    DWORD     LogContainerCountMin;
    DWORD     LogContainerCount;
    DWORD     LogGrowthIncrement;
    DWORD     LogAutoShrinkPercentage;
    DWORDLONG Reserved;
    WORD      LoggingMode;
  } TXFS_MODIFY_RM, *PTXFS_MODIFY_RM;

#define TXFS_RM_STATE_NOT_STARTED   0
#define TXFS_RM_STATE_STARTING      1
#define TXFS_RM_STATE_ACTIVE        2
#define TXFS_RM_STATE_SHUTTING_DOWN 3

#define TXFS_QUERY_RM_INFORMATION_VALID_FLAGS                                                                                               \
  (TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS | TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT | TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX | \
  TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN | TXFS_RM_FLAG_RESET_RM_AT_NEXT_START | TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START |              \
  TXFS_RM_FLAG_PREFER_CONSISTENCY | TXFS_RM_FLAG_PREFER_AVAILABILITY)

  typedef struct _TXFS_QUERY_RM_INFORMATION
  {
    DWORD         BytesRequired;
    DWORDLONG     TailLsn;
    DWORDLONG     CurrentLsn;
    DWORDLONG     ArchiveTailLsn;
    DWORDLONG     LogContainerSize;
    LARGE_INTEGER HighestVirtualClock;
    DWORD         LogContainerCount;
    DWORD         LogContainerCountMax;
    DWORD         LogContainerCountMin;
    DWORD         LogGrowthIncrement;
    DWORD         LogAutoShrinkPercentage;
    DWORD         Flags;
    WORD          LoggingMode;
    WORD          Reserved;
    DWORD         RmState;
    DWORDLONG     LogCapacity;
    DWORDLONG     LogFree;
    DWORDLONG     TopsSize;
    DWORDLONG     TopsUsed;
    DWORDLONG     TransactionCount;
    DWORDLONG     OnePCCount;
    DWORDLONG     TwoPCCount;
    DWORDLONG     NumberLogFileFull;
    DWORDLONG     OldestTransactionAge;
    GUID          RMName;
    DWORD         TmLogPathOffset;
  } TXFS_QUERY_RM_INFORMATION, *PTXFS_QUERY_RM_INFORMATION;

#define TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN      0x01
#define TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK 0x02

#define TXFS_ROLLFORWARD_REDO_VALID_FLAGS (TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN | TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK)

  typedef struct _TXFS_ROLLFORWARD_REDO_INFORMATION
  {
    LARGE_INTEGER LastVirtualClock;
    DWORDLONG     LastRedoLsn;
    DWORDLONG     HighestRecoveryLsn;
    DWORD         Flags;
  } TXFS_ROLLFORWARD_REDO_INFORMATION, *PTXFS_ROLLFORWARD_REDO_INFORMATION;

#define TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX              0x00000001
#define TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN              0x00000002
#define TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE                   0x00000004
#define TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS  0x00000008
#define TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT         0x00000010
#define TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE           0x00000020
#define TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX           0x00000040
#define TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN           0x00000080
#define TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT                  0x00000200
#define TXFS_START_RM_FLAG_LOGGING_MODE                         0x00000400
#define TXFS_START_RM_FLAG_PRESERVE_CHANGES                     0x00000800
#define TXFS_START_RM_FLAG_PREFER_CONSISTENCY                   0x00001000
#define TXFS_START_RM_FLAG_PREFER_AVAILABILITY                  0x00002000

#define TXFS_START_RM_VALID_FLAGS                                                                                                          \
  (TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX | TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN | TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE |       \
  TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS | TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT |                               \
  TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE | TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT | TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX | \
  TXFS_START_RM_FLAG_LOGGING_MODE | TXFS_START_RM_FLAG_PRESERVE_CHANGES | TXFS_START_RM_FLAG_PREFER_CONSISTENCY |                          \
  TXFS_START_RM_FLAG_PREFER_AVAILABILITY)

  typedef struct _TXFS_START_RM_INFORMATION
  {
    DWORD     Flags;
    DWORDLONG LogContainerSize;
    DWORD     LogContainerCountMin;
    DWORD     LogContainerCountMax;
    DWORD     LogGrowthIncrement;
    DWORD     LogAutoShrinkPercentage;
    DWORD     TmLogPathOffset;
    WORD      TmLogPathLength;
    WORD      LoggingMode;
    WORD      LogPathLength;
    WORD      Reserved;
    WCHAR     LogPath[1];
  } TXFS_START_RM_INFORMATION, *PTXFS_START_RM_INFORMATION;

  typedef struct _TXFS_GET_METADATA_INFO_OUT
  {
    struct
    {
      LONGLONG LowPart;
      LONGLONG HighPart;
    } TxfFileId;
    GUID      LockingTransaction;
    DWORDLONG LastLsn;
    DWORD     TransactionState;
  } TXFS_GET_METADATA_INFO_OUT, *PTXFS_GET_METADATA_INFO_OUT;

#define TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED 0x00000001
#define TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED 0x00000002

  typedef struct _TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY
  {
    DWORDLONG Offset;
    DWORD     NameFlags;
    LONGLONG  FileId;
    DWORD     Reserved1;
    DWORD     Reserved2;
    LONGLONG  Reserved3;
    WCHAR     FileName[1];
  } TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY, *PTXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY;

  typedef struct _TXFS_LIST_TRANSACTION_LOCKED_FILES
  {
    GUID      KtmTransaction;
    DWORDLONG NumberOfFiles;
    DWORDLONG BufferSizeRequired;
    DWORDLONG Offset;
  } TXFS_LIST_TRANSACTION_LOCKED_FILES, *PTXFS_LIST_TRANSACTION_LOCKED_FILES;

  typedef struct _TXFS_LIST_TRANSACTIONS_ENTRY
  {
    GUID     TransactionId;
    DWORD    TransactionState;
    DWORD    Reserved1;
    DWORD    Reserved2;
    LONGLONG Reserved3;
  } TXFS_LIST_TRANSACTIONS_ENTRY, *PTXFS_LIST_TRANSACTIONS_ENTRY;

  typedef struct _TXFS_LIST_TRANSACTIONS
  {
    DWORDLONG NumberOfTransactions;
    DWORDLONG BufferSizeRequired;
  } TXFS_LIST_TRANSACTIONS, *PTXFS_LIST_TRANSACTIONS;

  typedef struct _TXFS_READ_BACKUP_INFORMATION_OUT
  {
    __C89_NAMELESS union
    {
      DWORD BufferLength;
      BYTE  Buffer[1];
    } DUMMYUNIONNAME;
  } TXFS_READ_BACKUP_INFORMATION_OUT, *PTXFS_READ_BACKUP_INFORMATION_OUT;

  typedef struct _TXFS_WRITE_BACKUP_INFORMATION
  {
    BYTE Buffer[1];
  } TXFS_WRITE_BACKUP_INFORMATION, *PTXFS_WRITE_BACKUP_INFORMATION;

#define TXFS_TRANSACTED_VERSION_NONTRANSACTED 0xFFFFFFFE
#define TXFS_TRANSACTED_VERSION_UNCOMMITTED   0xFFFFFFFF

  typedef struct _TXFS_GET_TRANSACTED_VERSION
  {
    DWORD ThisBaseVersion;
    DWORD LatestVersion;
    WORD  ThisMiniVersion;
    WORD  FirstMiniVersion;
    WORD  LatestMiniVersion;
  } TXFS_GET_TRANSACTED_VERSION, *PTXFS_GET_TRANSACTED_VERSION;

#define TXFS_SAVEPOINT_SET       0x00000001
#define TXFS_SAVEPOINT_ROLLBACK  0x00000002
#define TXFS_SAVEPOINT_CLEAR     0x00000004
#define TXFS_SAVEPOINT_CLEAR_ALL 0x00000010

  typedef struct _TXFS_SAVEPOINT_INFORMATION
  {
    HANDLE KtmTransaction;
    DWORD  ActionCode;
    DWORD  SavepointId;
  } TXFS_SAVEPOINT_INFORMATION, *PTXFS_SAVEPOINT_INFORMATION;

  typedef struct _TXFS_CREATE_MINIVERSION_INFO
  {
    WORD  StructureVersion;
    WORD  StructureLength;
    DWORD BaseVersion;
    WORD  MiniVersion;
  } TXFS_CREATE_MINIVERSION_INFO, *PTXFS_CREATE_MINIVERSION_INFO;

  typedef struct _TXFS_TRANSACTION_ACTIVE_INFO
  {
    BOOLEAN TransactionsActiveAtSnapshot;
  } TXFS_TRANSACTION_ACTIVE_INFO, *PTXFS_TRANSACTION_ACTIVE_INFO;

  typedef struct _BOOT_AREA_INFO
  {
    DWORD BootSectorCount;
    struct
    {
      LARGE_INTEGER Offset;
    } BootSectors[2];
  } BOOT_AREA_INFO, *PBOOT_AREA_INFO;

  typedef struct _RETRIEVAL_POINTER_BASE
  {
    LARGE_INTEGER FileAreaOffset;
  } RETRIEVAL_POINTER_BASE, *PRETRIEVAL_POINTER_BASE;

  typedef struct _FILE_FS_PERSISTENT_VOLUME_INFORMATION
  {
    DWORD VolumeFlags;
    DWORD FlagMask;
    DWORD Version;
    DWORD Reserved;
  } FILE_FS_PERSISTENT_VOLUME_INFORMATION, *PFILE_FS_PERSISTENT_VOLUME_INFORMATION;

#define PERSISTENT_VOLUME_STATE_SHORT_NAME_CREATION_DISABLED    (0x00000001)
#define PERSISTENT_VOLUME_STATE_VOLUME_SCRUB_DISABLED           (0x00000002)
#define PERSISTENT_VOLUME_STATE_GLOBAL_METADATA_NO_SEEK_PENALTY (0x00000004)
#define PERSISTENT_VOLUME_STATE_LOCAL_METADATA_NO_SEEK_PENALTY  (0x00000008)
#define PERSISTENT_VOLUME_STATE_NO_HEAT_GATHERING               (0x00000010)
#define PERSISTENT_VOLUME_STATE_CONTAINS_BACKING_WIM            (0x00000020)
#define PERSISTENT_VOLUME_STATE_BACKED_BY_WIM                   (0x00000040)
#define PERSISTENT_VOLUME_STATE_NO_WRITE_AUTO_TIERING           (0x00000080)
#define PERSISTENT_VOLUME_STATE_TXF_DISABLED                    (0x00000100)
#define PERSISTENT_VOLUME_STATE_REALLOCATE_ALL_DATA_WRITES      (0x00000200)
#define PERSISTENT_VOLUME_STATE_CHKDSK_RAN_ONCE                 (0x00000400)
#define PERSISTENT_VOLUME_STATE_MODIFIED_BY_CHKDSK              (0x00000800)
#define PERSISTENT_VOLUME_STATE_DAX_FORMATTED                   (0x00001000)
#define PERSISTENT_VOLUME_STATE_DEV_VOLUME                      (0x00002000)
#define PERSISTENT_VOLUME_STATE_TRUSTED_VOLUME                  (0x00004000)

  typedef struct _FILE_SYSTEM_RECOGNITION_INFORMATION
  {
    CHAR FileSystem[9];
  } FILE_SYSTEM_RECOGNITION_INFORMATION, *PFILE_SYSTEM_RECOGNITION_INFORMATION;

#define OPLOCK_LEVEL_CACHE_READ   (0x00000001)
#define OPLOCK_LEVEL_CACHE_HANDLE (0x00000002)
#define OPLOCK_LEVEL_CACHE_WRITE  (0x00000004)

#define REQUEST_OPLOCK_INPUT_FLAG_REQUEST               (0x00000001)
#define REQUEST_OPLOCK_INPUT_FLAG_ACK                   (0x00000002)
#define REQUEST_OPLOCK_INPUT_FLAG_COMPLETE_ACK_ON_CLOSE (0x00000004)

#define REQUEST_OPLOCK_CURRENT_VERSION 1

  typedef struct _REQUEST_OPLOCK_INPUT_BUFFER
  {
    WORD  StructureVersion;
    WORD  StructureLength;
    DWORD RequestedOplockLevel;
    DWORD Flags;
  } REQUEST_OPLOCK_INPUT_BUFFER, *PREQUEST_OPLOCK_INPUT_BUFFER;

#define REQUEST_OPLOCK_OUTPUT_FLAG_ACK_REQUIRED             (0x00000001)
#define REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED           (0x00000002)
#define REQUEST_OPLOCK_OUTPUT_FLAG_WRITABLE_SECTION_PRESENT (0x00000004)

  typedef struct _REQUEST_OPLOCK_OUTPUT_BUFFER
  {
    WORD        StructureVersion;
    WORD        StructureLength;
    DWORD       OriginalOplockLevel;
    DWORD       NewOplockLevel;
    DWORD       Flags;
    ACCESS_MASK AccessMode;
    WORD        ShareMode;
  } REQUEST_OPLOCK_OUTPUT_BUFFER, *PREQUEST_OPLOCK_OUTPUT_BUFFER;

#ifndef _VIRTUAL_STORAGE_TYPE_DEFINED
# define _VIRTUAL_STORAGE_TYPE_DEFINED
  typedef struct _VIRTUAL_STORAGE_TYPE
  {
    DWORD DeviceId;
    GUID  VendorId;
  } VIRTUAL_STORAGE_TYPE, *PVIRTUAL_STORAGE_TYPE;
#endif

  typedef struct _STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST
  {
    DWORD RequestLevel;
    DWORD RequestFlags;
  } STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST, *PSTORAGE_QUERY_DEPENDENT_VOLUME_REQUEST;

#define QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_HOST_VOLUMES  0x1
#define QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_GUEST_VOLUMES 0x2

  typedef struct _STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY
  {
    DWORD                EntryLength;
    DWORD                DependencyTypeFlags;
    DWORD                ProviderSpecificFlags;
    VIRTUAL_STORAGE_TYPE VirtualStorageType;
  } STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY, *PSTORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY;

  typedef struct _STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY
  {
    DWORD                EntryLength;
    DWORD                DependencyTypeFlags;
    DWORD                ProviderSpecificFlags;
    VIRTUAL_STORAGE_TYPE VirtualStorageType;
    DWORD                AncestorLevel;
    DWORD                HostVolumeNameOffset;
    DWORD                HostVolumeNameSize;
    DWORD                DependentVolumeNameOffset;
    DWORD                DependentVolumeNameSize;
    DWORD                RelativePathOffset;
    DWORD                RelativePathSize;
    DWORD                DependentDeviceNameOffset;
    DWORD                DependentDeviceNameSize;
  } STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY, *PSTORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY;

  typedef struct _STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE
  {
    DWORD ResponseLevel;
    DWORD NumberEntries;
    __C89_NAMELESS union
    {
      STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY Lev1Depends[0];
      STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY Lev2Depends[0];
    } DUMMYUNIONNAME;
  } STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE, *PSTORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE;

#define SD_GLOBAL_CHANGE_TYPE_MACHINE_SID 1
#define SD_GLOBAL_CHANGE_TYPE_QUERY_STATS (1 << 16)
#define SD_GLOBAL_CHANGE_TYPE_ENUM_SDS    (2 << 16)

  typedef struct _SD_CHANGE_MACHINE_SID_INPUT
  {
    WORD CurrentMachineSIDOffset;
    WORD CurrentMachineSIDLength;
    WORD NewMachineSIDOffset;
    WORD NewMachineSIDLength;
  } SD_CHANGE_MACHINE_SID_INPUT, *PSD_CHANGE_MACHINE_SID_INPUT;

  typedef struct _SD_CHANGE_MACHINE_SID_OUTPUT
  {
    DWORDLONG NumSDChangedSuccess;
    DWORDLONG NumSDChangedFail;
    DWORDLONG NumSDUnused;
    DWORDLONG NumSDTotal;
    DWORDLONG NumMftSDChangedSuccess;
    DWORDLONG NumMftSDChangedFail;
    DWORDLONG NumMftSDTotal;
  } SD_CHANGE_MACHINE_SID_OUTPUT, *PSD_CHANGE_MACHINE_SID_OUTPUT;

  typedef struct _SD_QUERY_STATS_INPUT
  {
    DWORD Reserved;
  } SD_QUERY_STATS_INPUT, *PSD_QUERY_STATS_INPUT;

  typedef struct _SD_QUERY_STATS_OUTPUT
  {
    DWORDLONG SdsStreamSize;
    DWORDLONG SdsAllocationSize;
    DWORDLONG SiiStreamSize;
    DWORDLONG SiiAllocationSize;
    DWORDLONG SdhStreamSize;
    DWORDLONG SdhAllocationSize;
    DWORDLONG NumSDTotal;
    DWORDLONG NumSDUnused;
  } SD_QUERY_STATS_OUTPUT, *PSD_QUERY_STATS_OUTPUT;

  typedef struct _SD_ENUM_SDS_INPUT
  {
    DWORDLONG StartingOffset;
    DWORDLONG MaxSDEntriesToReturn;
  } SD_ENUM_SDS_INPUT, *PSD_ENUM_SDS_INPUT;

  typedef struct _SD_ENUM_SDS_ENTRY
  {
    DWORD     Hash;
    DWORD     SecurityId;
    DWORDLONG Offset;
    DWORD     Length;
    BYTE      Descriptor[1];
  } SD_ENUM_SDS_ENTRY, *PSD_ENUM_SDS_ENTRY;

  typedef struct _SD_ENUM_SDS_OUTPUT
  {
    DWORDLONG         NextOffset;
    DWORDLONG         NumSDEntriesReturned;
    DWORDLONG         NumSDBytesReturned;
    SD_ENUM_SDS_ENTRY SDEntry[1];
  } SD_ENUM_SDS_OUTPUT, *PSD_ENUM_SDS_OUTPUT;

  typedef struct _SD_GLOBAL_CHANGE_INPUT
  {
    DWORD Flags;
    DWORD ChangeType;
    __C89_NAMELESS union
    {
      SD_CHANGE_MACHINE_SID_INPUT SdChange;
      SD_QUERY_STATS_INPUT        SdQueryStats;
      SD_ENUM_SDS_INPUT           SdEnumSds;
    } DUMMYUNIONNAME;
  } SD_GLOBAL_CHANGE_INPUT, *PSD_GLOBAL_CHANGE_INPUT;

  typedef struct _SD_GLOBAL_CHANGE_OUTPUT
  {
    DWORD Flags;
    DWORD ChangeType;
    __C89_NAMELESS union
    {
      SD_CHANGE_MACHINE_SID_OUTPUT SdChange;
      SD_QUERY_STATS_OUTPUT        SdQueryStats;
      SD_ENUM_SDS_OUTPUT           SdEnumSds;
    } DUMMYUNIONNAME;
  } SD_GLOBAL_CHANGE_OUTPUT, *PSD_GLOBAL_CHANGE_OUTPUT;

  typedef struct _LOOKUP_STREAM_FROM_CLUSTER_INPUT
  {
    DWORD         Flags;
    DWORD         NumberOfClusters;
    LARGE_INTEGER Cluster[1];
  } LOOKUP_STREAM_FROM_CLUSTER_INPUT, *PLOOKUP_STREAM_FROM_CLUSTER_INPUT;

  typedef struct _LOOKUP_STREAM_FROM_CLUSTER_OUTPUT
  {
    DWORD Offset;
    DWORD NumberOfMatches;
    DWORD BufferSizeRequired;
  } LOOKUP_STREAM_FROM_CLUSTER_OUTPUT, *PLOOKUP_STREAM_FROM_CLUSTER_OUTPUT;

#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_PAGE_FILE       0x00000001
#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_DENY_DEFRAG_SET 0x00000002
#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_FS_SYSTEM_FILE  0x00000004
#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_TXF_SYSTEM_FILE 0x00000008
#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_MASK       0xff000000
#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_DATA       0x01000000
#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_INDEX      0x02000000
#define LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_SYSTEM     0x03000000

  typedef struct _LOOKUP_STREAM_FROM_CLUSTER_ENTRY
  {
    DWORD         OffsetToNext;
    DWORD         Flags;
    LARGE_INTEGER Reserved;
    LARGE_INTEGER Cluster;
    WCHAR         FileName[1];
  } LOOKUP_STREAM_FROM_CLUSTER_ENTRY, *PLOOKUP_STREAM_FROM_CLUSTER_ENTRY;

  typedef struct _FILE_TYPE_NOTIFICATION_INPUT
  {
    DWORD Flags;
    DWORD NumFileTypeIDs;
    GUID  FileTypeID[1];
  } FILE_TYPE_NOTIFICATION_INPUT, *PFILE_TYPE_NOTIFICATION_INPUT;

#define FILE_TYPE_NOTIFICATION_FLAG_USAGE_BEGIN 0x00000001
#define FILE_TYPE_NOTIFICATION_FLAG_USAGE_END   0x00000002

  DEFINE_GUID( FILE_TYPE_NOTIFICATION_GUID_PAGE_FILE,         0x0d0a64a1, 0x38fc, 0x4db8, 0x9f, 0xe7, 0x3f, 0x43, 0x52, 0xcd, 0x7c, 0x5c );
  DEFINE_GUID( FILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE,  0xb7624d64, 0xb9a3, 0x4cf8, 0x80, 0x11, 0x5b, 0x86, 0xc9, 0x40, 0xe7, 0xb7 );
  DEFINE_GUID( FILE_TYPE_NOTIFICATION_GUID_CRASHDUMP_FILE,    0x9d453eb7, 0xd2a6, 0x4dbd, 0xa2, 0xe3, 0xfb, 0xd0, 0xed, 0x91, 0x09, 0xa9 );

#define CSV_MGMTLOCK_CHECK_VOLUME_REDIRECTED 0x00000001

  typedef struct _CSV_MGMT_LOCK
  {
    DWORD Flags;
  } CSV_MGMT_LOCK, *PCSV_MGMT_LOCK;

  typedef struct _CSV_NAMESPACE_INFO
  {
    DWORD         Version;
    DWORD         DeviceNumber;
    LARGE_INTEGER StartingOffset;
    DWORD         SectorSize;
  } CSV_NAMESPACE_INFO, *PCSV_NAMESPACE_INFO;

#define CSV_NAMESPACE_INFO_V1     (sizeof(CSV_NAMESPACE_INFO))
#define CSV_INVALID_DEVICE_NUMBER 0xFFFFFFFF

  typedef enum _CSV_CONTROL_OP
  {
    CsvControlStartRedirectFile                  = 0x02,
    CsvControlStopRedirectFile                   = 0x03,
    CsvControlQueryRedirectState                 = 0x04,
    CsvControlQueryFileRevision                  = 0x06,
    CsvControlQueryMdsPath                       = 0x08,
    CsvControlQueryFileRevisionFileId128         = 0x09,
    CsvControlQueryVolumeRedirectState           = 0x0a,
    CsvControlEnableUSNRangeModificationTracking = 0x0d,
    CsvControlMarkHandleLocalVolumeMount         = 0x0e,
    CsvControlUnmarkHandleLocalVolumeMount       = 0x0f,
    CsvControlGetCsvFsMdsPathV2                  = 0x12,
    CsvControlDisableCaching                     = 0x13,
    CsvControlEnableCaching                      = 0x14,
    CsvControlStartForceDFO                      = 0x15,
    CsvControlStopForceDFO                       = 0x16,
    CsvControlQueryMdsPathNoPause                = 0x17,
    CsvControlSetVolumeId                        = 0x18,
    CsvControlQueryVolumeId                      = 0x19,
  } CSV_CONTROL_OP, *PCSV_CONTROL_OP;

  typedef struct _CSV_CONTROL_PARAM
  {
    CSV_CONTROL_OP Operation;
    LONGLONG       Unused;
  } CSV_CONTROL_PARAM, *PCSV_CONTROL_PARAM;

  typedef struct _CSV_QUERY_REDIRECT_STATE
  {
    DWORD   MdsNodeId;
    DWORD   DsNodeId;
    BOOLEAN FileRedirected;
  } CSV_QUERY_REDIRECT_STATE, *PCSV_QUERY_REDIRECT_STATE;

  typedef struct _CSV_QUERY_FILE_REVISION
  {
    LONGLONG FileId;
    LONGLONG FileRevision[3];
  } CSV_QUERY_FILE_REVISION, *PCSV_QUERY_FILE_REVISION;

  typedef struct _CSV_QUERY_FILE_REVISION_FILE_ID_128
  {
    FILE_ID_128 FileId;
    LONGLONG    FileRevision[3];
  } CSV_QUERY_FILE_REVISION_FILE_ID_128, *PCSV_QUERY_FILE_REVISION_FILE_ID_128;

  typedef struct _CSV_QUERY_MDS_PATH
  {
    DWORD MdsNodeId;
    DWORD DsNodeId;
    DWORD PathLength;
    WCHAR Path[1];
  } CSV_QUERY_MDS_PATH, *PCSV_QUERY_MDS_PATH;

  typedef enum _CSVFS_DISK_CONNECTIVITY
  {
    CsvFsDiskConnectivityNone          = 0,
    CsvFsDiskConnectivityMdsNodeOnly   = 1,
    CsvFsDiskConnectivitySubsetOfNodes = 2,
    CsvFsDiskConnectivityAllNodes      = 3
  } CSVFS_DISK_CONNECTIVITY, *PCSVFS_DISK_CONNECTIVITY;

  typedef struct _CSV_QUERY_VOLUME_REDIRECT_STATE
  {
    DWORD                   MdsNodeId;
    DWORD                   DsNodeId;
    BOOLEAN                 IsDiskConnected;
    BOOLEAN                 ClusterEnableDirectIo;
    CSVFS_DISK_CONNECTIVITY DiskConnectivity;
  } CSV_QUERY_VOLUME_REDIRECT_STATE, *PCSV_QUERY_VOLUME_REDIRECT_STATE;

#define CSV_QUERY_MDS_PATH_V2_VERSION_1                           1
#define CSV_QUERY_MDS_PATH_FLAG_STORAGE_ON_THIS_NODE_IS_CONNECTED 0x1
#define CSV_QUERY_MDS_PATH_FLAG_CSV_DIRECT_IO_ENABLED             0x2
#define CSV_QUERY_MDS_PATH_FLAG_SMB_BYPASS_CSV_ENABLED            0x4

  typedef struct _CSV_QUERY_MDS_PATH_V2
  {
    LONGLONG                Version;
    DWORD                   RequiredSize;
    DWORD                   MdsNodeId;
    DWORD                   DsNodeId;
    DWORD                   Flags;
    CSVFS_DISK_CONNECTIVITY DiskConnectivity;
    GUID                    VolumeId;
    DWORD                   IpAddressOffset;
    DWORD                   IpAddressLength;
    DWORD                   PathOffset;
    DWORD                   PathLength;
  } CSV_QUERY_MDS_PATH_V2, *PCSV_QUERY_MDS_PATH_V2;

  typedef struct _CSV_SET_VOLUME_ID
  {
    GUID VolumeId;
  } CSV_SET_VOLUME_ID, *PCSV_SET_VOLUME_ID;

  typedef struct _CSV_QUERY_VOLUME_ID
  {
    GUID VolumeId;
  } CSV_QUERY_VOLUME_ID, *PCSV_QUERY_VOLUME_ID;

  typedef enum _LMR_QUERY_INFO_CLASS
  {
    LMRQuerySessionInfo = 1,
  } LMR_QUERY_INFO_CLASS, *PLMR_QUERY_INFO_CLASS;

  typedef struct _LMR_QUERY_INFO_PARAM
  {
    LMR_QUERY_INFO_CLASS Operation;
  } LMR_QUERY_INFO_PARAM, *PLMR_QUERY_INFO_PARAM;

  typedef struct _LMR_QUERY_SESSION_INFO
  {
    UINT64 SessionId;
  } LMR_QUERY_SESSION_INFO, *PLMR_QUERY_SESSION_INFO;

  typedef struct _CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT
  {
    DWORDLONG VetoedFromAltitudeIntegral;
    DWORDLONG VetoedFromAltitudeDecimal;
    WCHAR     Reason[256];
  } CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT, *PCSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT;

  typedef enum _STORAGE_RESERVE_ID
  {
    StorageReserveIdNone = 0,
    StorageReserveIdHard,
    StorageReserveIdSoft,
    StorageReserveIdUpdateScratch,
    StorageReserveIdMax
  } STORAGE_RESERVE_ID, *PSTORAGE_RESERVE_ID;

  typedef struct _CSV_IS_OWNED_BY_CSVFS
  {
    BOOLEAN OwnedByCSVFS;
  } CSV_IS_OWNED_BY_CSVFS, *PCSV_IS_OWNED_BY_CSVFS;

  typedef struct _FILE_LEVEL_TRIM_RANGE
  {
    DWORDLONG Offset;
    DWORDLONG Length;
  } FILE_LEVEL_TRIM_RANGE, *PFILE_LEVEL_TRIM_RANGE;

  typedef struct _FILE_LEVEL_TRIM
  {
    DWORD                 Key;
    DWORD                 NumRanges;
    FILE_LEVEL_TRIM_RANGE Ranges[1];
  } FILE_LEVEL_TRIM, *PFILE_LEVEL_TRIM;

  typedef struct _FILE_LEVEL_TRIM_OUTPUT
  {
    DWORD NumRangesProcessed;
  } FILE_LEVEL_TRIM_OUTPUT, *PFILE_LEVEL_TRIM_OUTPUT;

#define QUERY_FILE_LAYOUT_RESTART                                          (0x00000001)
#define QUERY_FILE_LAYOUT_INCLUDE_NAMES                                    (0x00000002)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAMS                                  (0x00000004)
#define QUERY_FILE_LAYOUT_INCLUDE_EXTENTS                                  (0x00000008)
#define QUERY_FILE_LAYOUT_INCLUDE_EXTRA_INFO                               (0x00000010)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAMS_WITH_NO_CLUSTERS_ALLOCATED       (0x00000020)
#define QUERY_FILE_LAYOUT_INCLUDE_FULL_PATH_IN_NAMES                       (0x00000040)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION                       (0x00000080)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_DSC_ATTRIBUTE     (0x00000100)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_TXF_ATTRIBUTE     (0x00000200)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_EFS_ATTRIBUTE     (0x00000400)
#define QUERY_FILE_LAYOUT_INCLUDE_ONLY_FILES_WITH_SPECIFIC_ATTRIBUTES      (0x00000800)
#define QUERY_FILE_LAYOUT_INCLUDE_FILES_WITH_DSC_ATTRIBUTE                 (0x00001000)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_DATA_ATTRIBUTE    (0x00002000)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_REPARSE_ATTRIBUTE (0x00004000)
#define QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_EA_ATTRIBUTE      (0x00008000)

  typedef enum _QUERY_FILE_LAYOUT_FILTER_TYPE
  {
    QUERY_FILE_LAYOUT_FILTER_TYPE_NONE               = 0,
    QUERY_FILE_LAYOUT_FILTER_TYPE_CLUSTERS           = 1,
    QUERY_FILE_LAYOUT_FILTER_TYPE_FILEID             = 2,
    QUERY_FILE_LAYOUT_FILTER_TYPE_STORAGE_RESERVE_ID = 3,
    QUERY_FILE_LAYOUT_NUM_FILTER_TYPES
  } QUERY_FILE_LAYOUT_FILTER_TYPE;

  typedef struct _CLUSTER_RANGE
  {
    LARGE_INTEGER StartingCluster;
    LARGE_INTEGER ClusterCount;
  } CLUSTER_RANGE, *PCLUSTER_RANGE;

  typedef struct _FILE_REFERENCE_RANGE
  {
    DWORDLONG StartingFileReferenceNumber;
    DWORDLONG EndingFileReferenceNumber;
  } FILE_REFERENCE_RANGE, *PFILE_REFERENCE_RANGE;

  typedef struct _QUERY_FILE_LAYOUT_INPUT
  {
    __C89_NAMELESS union
    {
      DWORD FilterEntryCount;
      DWORD NumberOfPairs;
    } DUMMYUNIONNAME;
    DWORD                         Flags;
    QUERY_FILE_LAYOUT_FILTER_TYPE FilterType;
    DWORD                         Reserved;
    union
    {
      CLUSTER_RANGE        ClusterRanges[1];
      FILE_REFERENCE_RANGE FileReferenceRanges[1];
      STORAGE_RESERVE_ID   StorageReserveIds[1];
    } Filter;
  } QUERY_FILE_LAYOUT_INPUT, *PQUERY_FILE_LAYOUT_INPUT;

#define QUERY_FILE_LAYOUT_SINGLE_INSTANCED (0x00000001)

  typedef struct _QUERY_FILE_LAYOUT_OUTPUT
  {
    DWORD FileEntryCount;
    DWORD FirstFileOffset;
    DWORD Flags;
    DWORD Reserved;
  } QUERY_FILE_LAYOUT_OUTPUT, *PQUERY_FILE_LAYOUT_OUTPUT;

  typedef struct _FILE_LAYOUT_ENTRY
  {
    DWORD     Version;
    DWORD     NextFileOffset;
    DWORD     Flags;
    DWORD     FileAttributes;
    DWORDLONG FileReferenceNumber;
    DWORD     FirstNameOffset;
    DWORD     FirstStreamOffset;
    DWORD     ExtraInfoOffset;
    DWORD     ExtraInfoLength;
  } FILE_LAYOUT_ENTRY, *PFILE_LAYOUT_ENTRY;

#define FILE_LAYOUT_NAME_ENTRY_PRIMARY (0x00000001)
#define FILE_LAYOUT_NAME_ENTRY_DOS     (0x00000002)

  typedef struct _FILE_LAYOUT_NAME_ENTRY
  {
    DWORD     NextNameOffset;
    DWORD     Flags;
    DWORDLONG ParentFileReferenceNumber;
    DWORD     FileNameLength;
    DWORD     Reserved;
    WCHAR     FileName[1];
  } FILE_LAYOUT_NAME_ENTRY, *PFILE_LAYOUT_NAME_ENTRY;

  typedef struct _FILE_LAYOUT_INFO_ENTRY
  {
    struct
    {
      LARGE_INTEGER CreationTime;
      LARGE_INTEGER LastAccessTime;
      LARGE_INTEGER LastWriteTime;
      LARGE_INTEGER ChangeTime;
      DWORD         FileAttributes;
    } BasicInformation;
    DWORD              OwnerId;
    DWORD              SecurityId;
    USN                Usn;
    STORAGE_RESERVE_ID StorageReserveId;
  } FILE_LAYOUT_INFO_ENTRY, *PFILE_LAYOUT_INFO_ENTRY;

#define STREAM_LAYOUT_ENTRY_IMMOVABLE             (0x00000001)
#define STREAM_LAYOUT_ENTRY_PINNED                (0x00000002)
#define STREAM_LAYOUT_ENTRY_RESIDENT              (0x00000004)
#define STREAM_LAYOUT_ENTRY_NO_CLUSTERS_ALLOCATED (0x00000008)
#define STREAM_LAYOUT_ENTRY_HAS_INFORMATION       (0x00000010)
#define STREAM_EXTENT_ENTRY_AS_RETRIEVAL_POINTERS (0x00000001)
#define STREAM_EXTENT_ENTRY_ALL_EXTENTS           (0x00000002)

  typedef struct _STREAM_LAYOUT_ENTRY
  {
    DWORD         Version;
    DWORD         NextStreamOffset;
    DWORD         Flags;
    DWORD         ExtentInformationOffset;
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    DWORD         StreamInformationOffset;
    DWORD         AttributeTypeCode;
    DWORD         AttributeFlags;
    DWORD         StreamIdentifierLength;
    WCHAR         StreamIdentifier[1];
  } STREAM_LAYOUT_ENTRY, *PSTREAM_LAYOUT_ENTRY;

  typedef struct _STREAM_EXTENT_ENTRY
  {
    DWORD Flags;
    union
    {
      RETRIEVAL_POINTERS_BUFFER RetrievalPointers;
    } ExtentInformation;
  } STREAM_EXTENT_ENTRY, *PSTREAM_EXTENT_ENTRY;

#define CHECKSUM_TYPE_UNCHANGED         (WORD)0xFFFF
#define CHECKSUM_TYPE_NONE              (0)
#define CHECKSUM_TYPE_CRC32             (1)
#define CHECKSUM_TYPE_CRC64             (2)
#define CHECKSUM_TYPE_ECC               (3)
#define CHECKSUM_TYPE_SHA256            (4)
#define CHECKSUM_TYPE_XXH64             (5)
#define CHECKSUM_TYPE_FIRST_UNUSED_TYPE (6)

#define FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF (1)

  typedef struct _FSCTL_GET_INTEGRITY_INFORMATION_BUFFER
  {
    WORD  ChecksumAlgorithm;
    WORD  Reserved;
    DWORD Flags;
    DWORD ChecksumChunkSizeInBytes;
    DWORD ClusterSizeInBytes;
  } FSCTL_GET_INTEGRITY_INFORMATION_BUFFER, *PFSCTL_GET_INTEGRITY_INFORMATION_BUFFER;

  typedef struct _FSCTL_SET_INTEGRITY_INFORMATION_BUFFER
  {
    WORD  ChecksumAlgorithm;
    WORD  Reserved;
    DWORD Flags;
  } FSCTL_SET_INTEGRITY_INFORMATION_BUFFER, *PFSCTL_SET_INTEGRITY_INFORMATION_BUFFER;

  typedef struct _FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX
  {
    BYTE  EnableIntegrity;
    BYTE  KeepIntegrityStateUnchanged;
    WORD  Reserved;
    DWORD Flags;
    BYTE  Version;
    BYTE  Reserved2[7];
  } FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX, *PFSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX;

  typedef struct _FSCTL_OFFLOAD_READ_INPUT
  {
    DWORD     Size;
    DWORD     Flags;
    DWORD     TokenTimeToLive;
    DWORD     Reserved;
    DWORDLONG FileOffset;
    DWORDLONG CopyLength;
  } FSCTL_OFFLOAD_READ_INPUT, *PFSCTL_OFFLOAD_READ_INPUT;

  typedef struct _FSCTL_OFFLOAD_READ_OUTPUT
  {
    DWORD     Size;
    DWORD     Flags;
    DWORDLONG TransferLength;
    BYTE      Token[512];
  } FSCTL_OFFLOAD_READ_OUTPUT, *PFSCTL_OFFLOAD_READ_OUTPUT;

#define OFFLOAD_READ_FLAG_ALL_ZERO_BEYOND_CURRENT_RANGE (1)

  typedef struct _FSCTL_OFFLOAD_WRITE_INPUT
  {
    DWORD     Size;
    DWORD     Flags;
    DWORDLONG FileOffset;
    DWORDLONG CopyLength;
    DWORDLONG TransferOffset;
    BYTE      Token[512];
  } FSCTL_OFFLOAD_WRITE_INPUT, *PFSCTL_OFFLOAD_WRITE_INPUT;

  typedef struct _FSCTL_OFFLOAD_WRITE_OUTPUT
  {
    DWORD     Size;
    DWORD     Flags;
    DWORDLONG LengthWritten;
  } FSCTL_OFFLOAD_WRITE_OUTPUT, *PFSCTL_OFFLOAD_WRITE_OUTPUT;

  typedef struct _SET_PURGE_FAILURE_MODE_INPUT
  {
    DWORD Flags;
  } SET_PURGE_FAILURE_MODE_INPUT, *PSET_PURGE_FAILURE_MODE_INPUT;

#define SET_PURGE_FAILURE_MODE_ENABLED  0x00000001
#define SET_PURGE_FAILURE_MODE_DISABLED 0x00000002

  typedef struct _REPAIR_COPIES_INPUT
  {
    DWORD         Size;
    DWORD         Flags;
    LARGE_INTEGER FileOffset;
    DWORD         Length;
    DWORD         SourceCopy;
    DWORD         NumberOfRepairCopies;
    DWORD         RepairCopies[ANYSIZE_ARRAY];
  } REPAIR_COPIES_INPUT, *PREPAIR_COPIES_INPUT;

  typedef struct _REPAIR_COPIES_OUTPUT
  {
    DWORD         Size;
    DWORD         Status;
    LARGE_INTEGER ResumeFileOffset;
  } REPAIR_COPIES_OUTPUT, *PREPAIR_COPIES_OUTPUT;

#define FILE_REGION_USAGE_VALID_CACHED_DATA     0x00000001
#define FILE_REGION_USAGE_VALID_NONCACHED_DATA  0x00000002
#define FILE_REGION_USAGE_OTHER_PAGE_ALIGNMENT  0x00000004
#define FILE_REGION_USAGE_LARGE_PAGE_ALIGNMENT  0x00000008
#define FILE_REGION_USAGE_HUGE_PAGE_ALIGNMENT   0x00000010
#define FILE_REGION_USAGE_QUERY_ALIGNMENT       (FILE_REGION_USAGE_LARGE_PAGE_ALIGNMENT | FILE_REGION_USAGE_HUGE_PAGE_ALIGNMENT)

  typedef struct _FILE_REGION_INFO
  {
    LONGLONG FileOffset;
    LONGLONG Length;
    DWORD    Usage;
    DWORD    Reserved;
  } FILE_REGION_INFO, *PFILE_REGION_INFO;

  typedef struct _FILE_REGION_OUTPUT
  {
    DWORD            Flags;
    DWORD            TotalRegionEntryCount;
    DWORD            RegionEntryCount;
    DWORD            Reserved;
    FILE_REGION_INFO Region[1];
  } FILE_REGION_OUTPUT, *PFILE_REGION_OUTPUT;

  typedef struct _FILE_REGION_INPUT
  {
    LONGLONG FileOffset;
    LONGLONG Length;
    DWORD    DesiredUsage;
  } FILE_REGION_INPUT, *PFILE_REGION_INPUT;

#define VALID_WRITE_USN_REASON_MASK (USN_REASON_DATA_OVERWRITE | USN_REASON_CLOSE)

  typedef struct _WRITE_USN_REASON_INPUT
  {
    DWORD Flags;
    DWORD UsnReasonToWrite;
  } WRITE_USN_REASON_INPUT, *PWRITE_USN_REASON_INPUT;

#define FILE_STORAGE_TIER_NAME_LENGTH           (256)
#define FILE_STORAGE_TIER_DESCRIPTION_LENGTH    (512)
#define FILE_STORAGE_TIER_FLAG_NO_SEEK_PENALTY  (0x00020000)
#define FILE_STORAGE_TIER_FLAG_WRITE_BACK_CACHE (0x00200000)
#define FILE_STORAGE_TIER_FLAG_READ_CACHE       (0x00400000)
#define FILE_STORAGE_TIER_FLAG_PARITY           (0x00800000)
#define FILE_STORAGE_TIER_FLAG_SMR              (0x01000000)

  typedef enum _FILE_STORAGE_TIER_MEDIA_TYPE
  {
    FileStorageTierMediaTypeUnspecified = 0,
    FileStorageTierMediaTypeDisk        = 1,
    FileStorageTierMediaTypeSsd         = 2,
    FileStorageTierMediaTypeScm         = 4,
    FileStorageTierMediaTypeMax
  } FILE_STORAGE_TIER_MEDIA_TYPE, *PFILE_STORAGE_TIER_MEDIA_TYPE;

  typedef enum _FILE_STORAGE_TIER_CLASS
  {
    FileStorageTierClassUnspecified = 0,
    FileStorageTierClassCapacity,
    FileStorageTierClassPerformance,
    FileStorageTierClassMax
  } FILE_STORAGE_TIER_CLASS, *PFILE_STORAGE_TIER_CLASS;

  typedef struct _FILE_STORAGE_TIER
  {
    GUID                         Id;
    WCHAR                        Name[FILE_STORAGE_TIER_NAME_LENGTH];
    WCHAR                        Description[FILE_STORAGE_TIER_NAME_LENGTH];
    DWORDLONG                    Flags;
    DWORDLONG                    ProvisionedCapacity;
    FILE_STORAGE_TIER_MEDIA_TYPE MediaType;
    FILE_STORAGE_TIER_CLASS      Class;
  } FILE_STORAGE_TIER, *PFILE_STORAGE_TIER;

#define QUERY_STORAGE_CLASSES_FLAGS_MEASURE_WRITE    0x80000000
#define QUERY_STORAGE_CLASSES_FLAGS_MEASURE_READ     0x40000000
#define QUERY_STORAGE_CLASSES_FLAGS_NO_DEFRAG_VOLUME 0x20000000

  typedef struct _FSCTL_QUERY_STORAGE_CLASSES_OUTPUT
  {
    DWORD             Version;
    DWORD             Size;
    DWORD             Flags;
    DWORD             TotalNumberOfTiers;
    DWORD             NumberOfTiersReturned;
    FILE_STORAGE_TIER Tiers[ANYSIZE_ARRAY];
  } FSCTL_QUERY_STORAGE_CLASSES_OUTPUT, *PFSCTL_QUERY_STORAGE_CLASSES_OUTPUT;

#define FSCTL_QUERY_STORAGE_CLASSES_OUTPUT_VERSION sizeof(FSCTL_QUERY_STORAGE_CLASSES_OUTPUT)

#define QUERY_FILE_LAYOUT_REPARSE_DATA_INVALID (0x0001)
#define QUERY_FILE_LAYOUT_REPARSE_TAG_INVALID  (0x0002)

  typedef struct _STREAM_INFORMATION_ENTRY
  {
    DWORD Version;
    DWORD Flags;
    union _StreamInformation
    {
      struct _DesiredStorageClass
      {
        FILE_STORAGE_TIER_CLASS Class;
        DWORD                   Flags;
      } DesiredStorageClass;
      struct _DataStream
      {
        WORD      Length;
        WORD      Flags;
        DWORD     Reserved;
        DWORDLONG Vdl;
      } DataStream;
      struct _Reparse
      {
        WORD  Length;
        WORD  Flags;
        DWORD ReparseDataSize;
        DWORD ReparseDataOffset;
      } Reparse;
      struct _Ea
      {
        WORD  Length;
        WORD  Flags;
        DWORD EaSize;
        DWORD EaInformationOffset;
      } Ea;
    } StreamInformation;
  } STREAM_INFORMATION_ENTRY, *PSTREAM_INFORMATION_ENTRY;

  typedef struct _FSCTL_QUERY_REGION_INFO_INPUT
  {
    DWORD Version;
    DWORD Size;
    DWORD Flags;
    DWORD NumberOfTierIds;
    GUID  TierIds[ANYSIZE_ARRAY];
  } FSCTL_QUERY_REGION_INFO_INPUT, *PFSCTL_QUERY_REGION_INFO_INPUT;

#define FSCTL_QUERY_REGION_INFO_INPUT_VERSION sizeof(FSCTL_QUERY_REGION_INFO_INPUT)

  typedef struct _FILE_STORAGE_TIER_REGION
  {
    GUID      TierId;
    DWORDLONG Offset;
    DWORDLONG Length;
  } FILE_STORAGE_TIER_REGION, *PFILE_STORAGE_TIER_REGION;

  typedef struct _FSCTL_QUERY_REGION_INFO_OUTPUT
  {
    DWORD                    Version;
    DWORD                    Size;
    DWORD                    Flags;
    DWORD                    Reserved;
    DWORDLONG                Alignment;
    DWORD                    TotalNumberOfRegions;
    DWORD                    NumberOfRegionsReturned;
    FILE_STORAGE_TIER_REGION Regions[ANYSIZE_ARRAY];
  } FSCTL_QUERY_REGION_INFO_OUTPUT, *PFSCTL_QUERY_REGION_INFO_OUTPUT;

#define FSCTL_QUERY_REGION_INFO_OUTPUT_VERSION sizeof(FSCTL_QUERY_REGION_INFO_OUTPUT)

  typedef struct _FILE_DESIRED_STORAGE_CLASS_INFORMATION
  {
    FILE_STORAGE_TIER_CLASS Class;
    DWORD                   Flags;
  } FILE_DESIRED_STORAGE_CLASS_INFORMATION, *PFILE_DESIRED_STORAGE_CLASS_INFORMATION;

  typedef struct _DUPLICATE_EXTENTS_DATA
  {
    HANDLE        FileHandle;
    LARGE_INTEGER SourceFileOffset;
    LARGE_INTEGER TargetFileOffset;
    LARGE_INTEGER ByteCount;
  } DUPLICATE_EXTENTS_DATA, *PDUPLICATE_EXTENTS_DATA;

  typedef struct _DUPLICATE_EXTENTS_DATA32
  {
    UINT32        FileHandle;
    LARGE_INTEGER SourceFileOffset;
    LARGE_INTEGER TargetFileOffset;
    LARGE_INTEGER ByteCount;
  } DUPLICATE_EXTENTS_DATA32, *PDUPLICATE_EXTENTS_DATA32;

#define DUPLICATE_EXTENTS_DATA_EX_SOURCE_ATOMIC 0x00000001
#define DUPLICATE_EXTENTS_DATA_EX_ASYNC         0x00000002

  typedef struct _DUPLICATE_EXTENTS_DATA_EX
  {
    SIZE_T        Size;
    HANDLE        FileHandle;
    LARGE_INTEGER SourceFileOffset;
    LARGE_INTEGER TargetFileOffset;
    LARGE_INTEGER ByteCount;
    DWORD         Flags;
  } DUPLICATE_EXTENTS_DATA_EX, *PDUPLICATE_EXTENTS_DATA_EX;

  typedef struct _DUPLICATE_EXTENTS_DATA_EX32
  {
    DWORD32       Size;
    DWORD32       FileHandle;
    LARGE_INTEGER SourceFileOffset;
    LARGE_INTEGER TargetFileOffset;
    LARGE_INTEGER ByteCount;
    DWORD         Flags;
  } DUPLICATE_EXTENTS_DATA_EX32, *PDUPLICATE_EXTENTS_DATA_EX32;

  typedef enum _DUPLICATE_EXTENTS_STATE
  {
    FileSnapStateInactive = 0,
    FileSnapStateSource,
    FileSnapStateTarget,
  } DUPLICATE_EXTENTS_STATE, *PDUPLICATE_EXTENTS_STATE;

  typedef struct _ASYNC_DUPLICATE_EXTENTS_STATUS
  {
    DWORD                   Version;
    DUPLICATE_EXTENTS_STATE State;
    DWORDLONG               SourceFileOffset;
    DWORDLONG               TargetFileOffset;
    DWORDLONG               ByteCount;
    DWORDLONG               BytesDuplicated;
  } ASYNC_DUPLICATE_EXTENTS_STATUS, *PASYNC_DUPLICATE_EXTENTS_STATUS;

#define ASYNC_DUPLICATE_EXTENTS_STATUS_V1 sizeof(ASYNC_DUPLICATE_EXTENTS_STATUS)

#define REFS_SMR_VOLUME_INFO_OUTPUT_VERSION_V0 0
#define REFS_SMR_VOLUME_INFO_OUTPUT_VERSION_V1 1

  typedef enum _REFS_SMR_VOLUME_GC_STATE
  {
    SmrGcStateInactive        = 0,
    SmrGcStatePaused          = 1,
    SmrGcStateActive          = 2,
    SmrGcStateActiveFullSpeed = 3,
  } REFS_SMR_VOLUME_GC_STATE, *PREFS_SMR_VOLUME_GC_STATE;

  typedef struct _REFS_SMR_VOLUME_INFO_OUTPUT
  {
    DWORD                    Version;
    DWORD                    Flags;
    LARGE_INTEGER            SizeOfRandomlyWritableTier;
    LARGE_INTEGER            FreeSpaceInRandomlyWritableTier;
    LARGE_INTEGER            SizeofSMRTier;
    LARGE_INTEGER            FreeSpaceInSMRTier;
    LARGE_INTEGER            UsableFreeSpaceInSMRTier;
    REFS_SMR_VOLUME_GC_STATE VolumeGcState;
    DWORD                    VolumeGcLastStatus;
    DWORD                    CurrentGcBandFillPercentage;
    DWORDLONG                Unused[6];
  } REFS_SMR_VOLUME_INFO_OUTPUT, *PREFS_SMR_VOLUME_INFO_OUTPUT;

#define REFS_SMR_VOLUME_GC_PARAMETERS_VERSION_V1 1

  typedef enum _REFS_SMR_VOLUME_GC_ACTION
  {
    SmrGcActionStart          = 1,
    SmrGcActionStartFullSpeed = 2,
    SmrGcActionPause          = 3,
    SmrGcActionStop           = 4,
  } REFS_SMR_VOLUME_GC_ACTION, *PREFS_SMR_VOLUME_GC_ACTION;

  typedef enum _REFS_SMR_VOLUME_GC_METHOD
  {
    SmrGcMethodCompaction  = 1,
    SmrGcMethodCompression = 2,
    SmrGcMethodRotation    = 3,
  } REFS_SMR_VOLUME_GC_METHOD, *PREFS_SMR_VOLUME_GC_METHOD;

  typedef struct _REFS_SMR_VOLUME_GC_PARAMETERS
  {
    DWORD                     Version;
    DWORD                     Flags;
    REFS_SMR_VOLUME_GC_ACTION Action;
    REFS_SMR_VOLUME_GC_METHOD Method;
    DWORD                     IoGranularity;
    DWORD                     CompressionFormat;
    DWORDLONG                 Unused[8];
  } REFS_SMR_VOLUME_GC_PARAMETERS, *PREFS_SMR_VOLUME_GC_PARAMETERS;

#define STREAMS_INVALID_ID (0)
#define STREAMS_MAX_ID     (MAXWORD)

  typedef struct _STREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER
  {
    DWORD OptimalWriteSize;
    DWORD StreamGranularitySize;
    DWORD StreamIdMin;
    DWORD StreamIdMax;
  } STREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER, *PSTREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER;

#define STREAMS_ASSOCIATE_ID_CLEAR (0x1)
#define STREAMS_ASSOCIATE_ID_SET   (0x2)

  typedef struct _STREAMS_ASSOCIATE_ID_INPUT_BUFFER
  {
    DWORD Flags;
    DWORD StreamId;
  } STREAMS_ASSOCIATE_ID_INPUT_BUFFER, *PSTREAMS_ASSOCIATE_ID_INPUT_BUFFER;

  typedef struct _STREAMS_QUERY_ID_OUTPUT_BUFFER
  {
    DWORD StreamId;
  } STREAMS_QUERY_ID_OUTPUT_BUFFER, *PSTREAMS_QUERY_ID_OUTPUT_BUFFER;

  typedef struct _QUERY_BAD_RANGES_INPUT_RANGE
  {
    DWORDLONG StartOffset;
    DWORDLONG LengthInBytes;
  } QUERY_BAD_RANGES_INPUT_RANGE, *PQUERY_BAD_RANGES_INPUT_RANGE;

  typedef struct _QUERY_BAD_RANGES_INPUT
  {
    DWORD                        Flags;
    DWORD                        NumRanges;
    QUERY_BAD_RANGES_INPUT_RANGE Ranges[1];
  } QUERY_BAD_RANGES_INPUT, *PQUERY_BAD_RANGES_INPUT;

  typedef struct _QUERY_BAD_RANGES_OUTPUT_RANGE
  {
    DWORD     Flags;
    DWORD     Reserved;
    DWORDLONG StartOffset;
    DWORDLONG LengthInBytes;
  } QUERY_BAD_RANGES_OUTPUT_RANGE, *PQUERY_BAD_RANGES_OUTPUT_RANGE;

  typedef struct _QUERY_BAD_RANGES_OUTPUT
  {
    DWORD                         Flags;
    DWORD                         NumBadRanges;
    DWORDLONG                     NextOffsetToLookUp;
    QUERY_BAD_RANGES_OUTPUT_RANGE BadRanges[1];
  } QUERY_BAD_RANGES_OUTPUT, *PQUERY_BAD_RANGES_OUTPUT;

  typedef struct _SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT
  {
    DWORD     Flags;
    DWORD     AlignmentShift;
    DWORDLONG FileOffsetToAlign;
    DWORD     FallbackAlignmentShift;
  } SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT, *PSET_DAX_ALLOC_ALIGNMENT_HINT_INPUT;

#define DAX_ALLOC_ALIGNMENT_FLAG_MANDATORY          (0x00000001)
#define DAX_ALLOC_ALIGNMENT_FLAG_FALLBACK_SPECIFIED (0x00000002)

  typedef enum _VIRTUAL_STORAGE_BEHAVIOR_CODE
  {
    VirtualStorageBehaviorUndefined           = 0,
    VirtualStorageBehaviorCacheWriteThrough   = 1,
    VirtualStorageBehaviorCacheWriteBack      = 2,
    VirtualStorageBehaviorStopIoProcessing    = 3,
    VirtualStorageBehaviorRestartIoProcessing = 4
  } VIRTUAL_STORAGE_BEHAVIOR_CODE, *PVIRTUAL_STORAGE_BEHAVIOR_CODE;

  typedef struct _VIRTUAL_STORAGE_SET_BEHAVIOR_INPUT
  {
    DWORD                         Size;
    VIRTUAL_STORAGE_BEHAVIOR_CODE BehaviorCode;
  } VIRTUAL_STORAGE_SET_BEHAVIOR_INPUT, *PVIRTUAL_STORAGE_SET_BEHAVIOR_INPUT;

  typedef struct _ENCRYPTION_KEY_CTRL_INPUT
  {
    DWORD     HeaderSize;
    DWORD     StructureSize;
    WORD      KeyOffset;
    WORD      KeySize;
    DWORD     DplLock;
    DWORDLONG DplUserId;
    DWORDLONG DplCredentialId;
  } ENCRYPTION_KEY_CTRL_INPUT, *PENCRYPTION_KEY_CTRL_INPUT;

#define WOF_CURRENT_VERSION (0x00000001)

#define WOF_PROVIDER_WIM   (0x00000001)
#define WOF_PROVIDER_FILE  (0x00000002)
#define WOF_PROVIDER_CLOUD (0x00000003)

  typedef struct _WOF_EXTERNAL_INFO
  {
    DWORD Version;
    DWORD Provider;
  } WOF_EXTERNAL_INFO, *PWOF_EXTERNAL_INFO;

  typedef struct _WOF_EXTERNAL_FILE_ID
  {
    FILE_ID_128 FileId;
  } WOF_EXTERNAL_FILE_ID, *PWOF_EXTERNAL_FILE_ID;

  typedef struct _WOF_VERSION_INFO
  {
    DWORD WofVersion;
  } WOF_VERSION_INFO, *PWOF_VERSION_INFO;

#ifndef WIM_PROVIDER_HASH_SIZE
# define WIM_PROVIDER_HASH_SIZE 20
#endif

#define WIM_PROVIDER_CURRENT_VERSION          (0x00000001)
#define WIM_PROVIDER_EXTERNAL_FLAG_NOT_ACTIVE (0x00000001)
#define WIM_PROVIDER_EXTERNAL_FLAG_SUSPENDED  (0x00000002)

  typedef struct _WIM_PROVIDER_EXTERNAL_INFO
  {
    DWORD         Version;
    DWORD         Flags;
    LARGE_INTEGER DataSourceId;
    BYTE          ResourceHash[WIM_PROVIDER_HASH_SIZE];
  } WIM_PROVIDER_EXTERNAL_INFO, *PWIM_PROVIDER_EXTERNAL_INFO;

#define WIM_BOOT_OS_WIM     (0x00000001)
#define WIM_BOOT_NOT_OS_WIM (0x00000000)

  typedef struct _WIM_PROVIDER_ADD_OVERLAY_INPUT
  {
    DWORD WimType;
    DWORD WimIndex;
    DWORD WimFileNameOffset;
    DWORD WimFileNameLength;
  } WIM_PROVIDER_ADD_OVERLAY_INPUT, *PWIM_PROVIDER_ADD_OVERLAY_INPUT;

  typedef struct _WIM_PROVIDER_UPDATE_OVERLAY_INPUT
  {
    LARGE_INTEGER DataSourceId;
    DWORD         WimFileNameOffset;
    DWORD         WimFileNameLength;
  } WIM_PROVIDER_UPDATE_OVERLAY_INPUT, *PWIM_PROVIDER_UPDATE_OVERLAY_INPUT;

  typedef struct _WIM_PROVIDER_REMOVE_OVERLAY_INPUT
  {
    LARGE_INTEGER DataSourceId;
  } WIM_PROVIDER_REMOVE_OVERLAY_INPUT, *PWIM_PROVIDER_REMOVE_OVERLAY_INPUT;

  typedef struct _WIM_PROVIDER_SUSPEND_OVERLAY_INPUT
  {
    LARGE_INTEGER DataSourceId;
  } WIM_PROVIDER_SUSPEND_OVERLAY_INPUT, *PWIM_PROVIDER_SUSPEND_OVERLAY_INPUT;

  typedef struct _WIM_PROVIDER_OVERLAY_ENTRY
  {
    DWORD         NextEntryOffset;
    LARGE_INTEGER DataSourceId;
    GUID          WimGuid;
    DWORD         WimFileNameOffset;
    DWORD         WimType;
    DWORD         WimIndex;
    DWORD         Flags;
  } WIM_PROVIDER_OVERLAY_ENTRY, *PWIM_PROVIDER_OVERLAY_ENTRY;

#define FILE_PROVIDER_CURRENT_VERSION        (0x00000001)
#define FILE_PROVIDER_SINGLE_FILE            (0x00000001)
#define FILE_PROVIDER_COMPRESSION_XPRESS4K   (0x00000000)
#define FILE_PROVIDER_COMPRESSION_LZX        (0x00000001)
#define FILE_PROVIDER_COMPRESSION_XPRESS8K   (0x00000002)
#define FILE_PROVIDER_COMPRESSION_XPRESS16K  (0x00000003)
#define FILE_PROVIDER_COMPRESSION_MAXIMUM    (0x00000004)
#define FILE_PROVIDER_FLAG_COMPRESS_ON_WRITE (0x00000001)

  typedef struct _FILE_PROVIDER_EXTERNAL_INFO_V0
  {
    DWORD Version;
    DWORD Algorithm;
  } FILE_PROVIDER_EXTERNAL_INFO_V0, *PFILE_PROVIDER_EXTERNAL_INFO_V0;

  typedef struct _FILE_PROVIDER_EXTERNAL_INFO_V1
  {
    DWORD Version;
    DWORD Algorithm;
    DWORD Flags;
  } FILE_PROVIDER_EXTERNAL_INFO_V1, *PFILE_PROVIDER_EXTERNAL_INFO_V1;

  typedef  FILE_PROVIDER_EXTERNAL_INFO_V1  FILE_PROVIDER_EXTERNAL_INFO;
  typedef PFILE_PROVIDER_EXTERNAL_INFO_V1 PFILE_PROVIDER_EXTERNAL_INFO;

  typedef struct _CONTAINER_VOLUME_STATE
  {
    DWORD Flags;
  } CONTAINER_VOLUME_STATE, *PCONTAINER_VOLUME_STATE;

#define CONTAINER_VOLUME_STATE_HOSTING_CONTAINER (0x00000001)

  typedef struct _CONTAINER_ROOT_INFO_INPUT
  {
    DWORD Flags;
  } CONTAINER_ROOT_INFO_INPUT, *PCONTAINER_ROOT_INFO_INPUT;

  typedef struct _CONTAINER_ROOT_INFO_OUTPUT
  {
    WORD ContainerRootIdLength;
    BYTE ContainerRootId[ANYSIZE_ARRAY];
  } CONTAINER_ROOT_INFO_OUTPUT, *PCONTAINER_ROOT_INFO_OUTPUT;

#define CONTAINER_ROOT_INFO_FLAG_SCRATCH_ROOT                  (0x00000001)
#define CONTAINER_ROOT_INFO_FLAG_LAYER_ROOT                    (0x00000002)
#define CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_ROOT           (0x00000004)
#define CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_TARGET_ROOT    (0x00000008)
#define CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_EXCEPTION_ROOT (0x00000010)
#define CONTAINER_ROOT_INFO_FLAG_BIND_ROOT                     (0x00000020)
#define CONTAINER_ROOT_INFO_FLAG_BIND_TARGET_ROOT              (0x00000040)
#define CONTAINER_ROOT_INFO_FLAG_BIND_EXCEPTION_ROOT           (0x00000080)
#define CONTAINER_ROOT_INFO_FLAG_BIND_DO_NOT_MAP_NAME          (0x00000100)
#define CONTAINER_ROOT_INFO_FLAG_UNION_LAYER_ROOT              (0x00000200)
#define CONTAINER_ROOT_INFO_VALID_FLAGS                        (0x000003ff)

  typedef struct _VIRTUALIZATION_INSTANCE_INFO_INPUT
  {
    DWORD NumberOfWorkerThreads;
    DWORD Flags;
  } VIRTUALIZATION_INSTANCE_INFO_INPUT, *PVIRTUALIZATION_INSTANCE_INFO_INPUT;

#define PROJFS_PROTOCOL_VERSION 3

  typedef struct _VIRTUALIZATION_INSTANCE_INFO_INPUT_EX
  {
    WORD  HeaderSize;
    DWORD Flags;
    DWORD NotificationInfoSize;
    WORD  NotificationInfoOffset;
    WORD  ProviderMajorVersion;
  } VIRTUALIZATION_INSTANCE_INFO_INPUT_EX, *PVIRTUALIZATION_INSTANCE_INFO_INPUT_EX;

  typedef struct _VIRTUALIZATION_INSTANCE_INFO_OUTPUT
  {
    GUID VirtualizationInstanceID;
  } VIRTUALIZATION_INSTANCE_INFO_OUTPUT, *PVIRTUALIZATION_INSTANCE_INFO_OUTPUT;

  typedef struct _GET_FILTER_FILE_IDENTIFIER_INPUT
  {
    WORD  AltitudeLength;
    WCHAR Altitude[ANYSIZE_ARRAY];
  } GET_FILTER_FILE_IDENTIFIER_INPUT, *PGET_FILTER_FILE_IDENTIFIER_INPUT;

  typedef struct _GET_FILTER_FILE_IDENTIFIER_OUTPUT
  {
    WORD FilterFileIdentifierLength;
    BYTE FilterFileIdentifier[ANYSIZE_ARRAY];
  } GET_FILTER_FILE_IDENTIFIER_OUTPUT, *PGET_FILTER_FILE_IDENTIFIER_OUTPUT;

  typedef enum _FS_BPIO_OPERATIONS
  {
    FS_BPIO_OP_ENABLE              = 1,
    FS_BPIO_OP_DISABLE             = 2,
    FS_BPIO_OP_QUERY               = 3,
    FS_BPIO_OP_VOLUME_STACK_PAUSE  = 4,
    FS_BPIO_OP_VOLUME_STACK_RESUME = 5,
    FS_BPIO_OP_STREAM_PAUSE        = 6,
    FS_BPIO_OP_STREAM_RESUME       = 7,
    FS_BPIO_OP_GET_INFO            = 8,
    FS_BPIO_OP_MAX_OPERATION
  } FS_BPIO_OPERATIONS;

  typedef enum _FS_BPIO_INFLAGS
  {
    FSBPIO_INFL_None                     = 0,
    FSBPIO_INFL_SKIP_STORAGE_STACK_QUERY = 1,
  } FS_BPIO_INFLAGS;

  DEFINE_ENUM_FLAG_OPERATORS(FS_BPIO_INFLAGS)

  typedef struct _FS_BPIO_INPUT
  {
    FS_BPIO_OPERATIONS Operation;
    FS_BPIO_INFLAGS    InFlags;
    DWORDLONG          Reserved1;
    DWORDLONG          Reserved2;
  } FS_BPIO_INPUT, *PFS_BPIO_INPUT;

  typedef enum _FS_BPIO_OUTFLAGS
  {
    FSBPIO_OUTFL_None                       = 0,
    FSBPIO_OUTFL_VOLUME_STACK_BYPASS_PAUSED = 0x00000001,
    FSBPIO_OUTFL_STREAM_BYPASS_PAUSED       = 0x00000002,
    FSBPIO_OUTFL_FILTER_ATTACH_BLOCKED      = 0x00000004,
    FSBPIO_OUTFL_COMPATIBLE_STORAGE_DRIVER  = 0x00000008,
  } FS_BPIO_OUTFLAGS;

  DEFINE_ENUM_FLAG_OPERATORS(FS_BPIO_OUTFLAGS)

  typedef struct _FS_BPIO_RESULTS
  {
    DWORD OpStatus;
    WORD  FailingDriverNameLen;
    WCHAR FailingDriverName[32];
    WORD  FailureReasonLen;
    WCHAR FailureReason[128];
  } FS_BPIO_RESULTS, *PFS_BPIO_RESULTS;

  typedef struct _FS_BPIO_INFO
  {
    DWORD ActiveBypassIoCount;
    WORD  StorageDriverNameLen;
    WCHAR StorageDriverName[32];
  } FS_BPIO_INFO, *PFS_BPIO_INFO;

  typedef struct _FS_BPIO_OUTPUT
  {
    FS_BPIO_OPERATIONS Operation;
    FS_BPIO_OUTFLAGS OutFlags;
    DWORDLONG Reserved1;
    DWORDLONG Reserved2;
    __C89_NAMELESS union
    {
      FS_BPIO_RESULTS Enable;
      FS_BPIO_RESULTS Query;
      FS_BPIO_RESULTS VolumeStackResume;
      FS_BPIO_RESULTS StreamResume;
      FS_BPIO_INFO    GetInfo;
    };
  } FS_BPIO_OUTPUT, *PFS_BPIO_OUTPUT;

#define FS_BPIO_OUTPUT_ENABLE_SIZE              (RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, Enable))
#define FS_BPIO_OUTPUT_QUERY_SIZE               (RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, Query))
#define FS_BPIO_OUTPUT_DISABLE_SIZE             ((size_t)FIELD_OFFSET(FS_BPIO_OUTPUT, Enable))
#define FS_BPIO_OUTPUT_VOLUME_STACK_PAUSE_SIZE  ((size_t)FIELD_OFFSET(FS_BPIO_OUTPUT, Enable))
#define FS_BPIO_OUTPUT_VOLUME_STACK_RESUME_SIZE (RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, VolumeStackResume))
#define FS_BPIO_OUTPUT_STREAM_PAUSE_SIZE        ((size_t)FIELD_OFFSET(FS_BPIO_OUTPUT, Enable))
#define FS_BPIO_OUTPUT_STREAM_RESUME_SIZE       (RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, StreamResume))
#define FS_BPIO_OUTPUT_GET_INFO_SIZE            (RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, GetInfo))

#endif  /* _FILESYSTEMFSCTL_ */

#ifndef SMB_CCF_APP_INSTANCE_EA_NAME
# define SMB_CCF_APP_INSTANCE_EA_NAME "ClusteredApplicationInstance"
#endif

#ifndef _NETWORK_APP_INSTANCE_EA_DEFINED
#define _NETWORK_APP_INSTANCE_EA_DEFINED

#ifndef NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR
# define NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR 0x00000001
#endif

  typedef struct _NETWORK_APP_INSTANCE_EA
  {
    GUID  AppInstanceID;
    DWORD CsvFlags;
  } NETWORK_APP_INSTANCE_EA, *PNETWORK_APP_INSTANCE_EA;

#endif  /* _NETWORK_APP_INSTANCE_EA_DEFINED */

#ifndef SMB_SHARE_FLUSH_AND_PURGE_INPUT_DESCRIPTORS_DEFINED
#define SMB_SHARE_FLUSH_AND_PURGE_INPUT_DESCRIPTORS_DEFINED

  typedef struct _SMB_SHARE_FLUSH_AND_PURGE_INPUT
  {
    WORD Version;
  } SMB_SHARE_FLUSH_AND_PURGE_INPUT, *PSMB_SHARE_FLUSH_AND_PURGE_INPUT;

  typedef struct _SMB_SHARE_FLUSH_AND_PURGE_INPUT const *PCSMB_SHARE_FLUSH_AND_PURGE_INPUT;

  typedef struct _SMB_SHARE_FLUSH_AND_PURGE_OUTPUT
  {
    DWORD cEntriesPurged;
  } SMB_SHARE_FLUSH_AND_PURGE_OUTPUT, *PSMB_SHARE_FLUSH_AND_PURGE_OUTPUT;

  typedef struct _SMB_SHARE_FLUSH_AND_PURGE_OUTPUT const *PCSMB_SHARE_FLUSH_AND_PURGE_OUTPUT;

#endif  /* SMB_SHARE_FLUSH_AND_PURGE_INPUT_DESCRIPTORS_DEFINED */

#define IOCTL_VOLUME_BASE ((DWORD)'V')

#define IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS CTL_CODE(IOCTL_VOLUME_BASE, 0,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_VOLUME_ONLINE                  CTL_CODE(IOCTL_VOLUME_BASE, 2,  METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLUME_OFFLINE                 CTL_CODE(IOCTL_VOLUME_BASE, 3,  METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VOLUME_IS_CLUSTERED            CTL_CODE(IOCTL_VOLUME_BASE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_VOLUME_GET_GPT_ATTRIBUTES      CTL_CODE(IOCTL_VOLUME_BASE, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)

  typedef struct _DISK_EXTENT
  {
    DWORD         DiskNumber;
    LARGE_INTEGER StartingOffset;
    LARGE_INTEGER ExtentLength;
  } DISK_EXTENT, *PDISK_EXTENT;

  typedef struct _VOLUME_DISK_EXTENTS
  {
    DWORD       NumberOfDiskExtents;
    DISK_EXTENT Extents[ANYSIZE_ARRAY];
  } VOLUME_DISK_EXTENTS, *PVOLUME_DISK_EXTENTS;

  typedef struct _VOLUME_GET_GPT_ATTRIBUTES_INFORMATION
  {
    DWORDLONG GptAttributes;
  } VOLUME_GET_GPT_ATTRIBUTES_INFORMATION, *PVOLUME_GET_GPT_ATTRIBUTES_INFORMATION;

#ifndef _IO_IRP_EXT_TRACK_OFFSET_HEADER_
#define _IO_IRP_EXT_TRACK_OFFSET_HEADER_

  struct _IO_IRP_EXT_TRACK_OFFSET_HEADER;

  typedef VOID (*PIO_IRP_EXT_PROCESS_TRACKED_OFFSET_CALLBACK)(struct _IO_IRP_EXT_TRACK_OFFSET_HEADER *SourceContext, struct _IO_IRP_EXT_TRACK_OFFSET_HEADER *TargetContext, LONGLONG RelativeOffset);

#define IRP_EXT_TRACK_OFFSET_HEADER_VALIDATION_VALUE 'TO'

  typedef struct _IO_IRP_EXT_TRACK_OFFSET_HEADER
  {
    WORD                                        Validation;
    WORD                                        Flags;
    PIO_IRP_EXT_PROCESS_TRACKED_OFFSET_CALLBACK TrackedOffsetCallback;
  } IO_IRP_EXT_TRACK_OFFSET_HEADER, *PIO_IRP_EXT_TRACK_OFFSET_HEADER;

#define EFS_TRACKED_OFFSET_HEADER_FLAG    0x0001
#define SPACES_TRACKED_OFFSET_HEADER_FLAG 0x0002

#endif  /* _IO_IRP_EXT_TRACK_OFFSET_HEADER_ */

#endif  /* _WINIOCTL_ */
