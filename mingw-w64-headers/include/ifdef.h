/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_IFDEF
#define _INC_IFDEF

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#ifdef __cplusplus
extern "C" {
#endif

#include <ipifcons.h>

  typedef UINT32 NET_IF_COMPARTMENT_ID, *PNET_IF_COMPARTMENT_ID;

#define NET_IF_COMPARTMENT_ID_UNSPECIFIED (NET_IF_COMPARTMENT_ID)0
#define NET_IF_COMPARTMENT_ID_PRIMARY     (NET_IF_COMPARTMENT_ID)1

  typedef GUID NET_IF_NETWORK_GUID, *PNET_IF_NETWORK_GUID;

  typedef enum _NET_IF_OPER_STATUS
  {
    NET_IF_OPER_STATUS_UP               = 1,
    NET_IF_OPER_STATUS_DOWN             = 2,
    NET_IF_OPER_STATUS_TESTING          = 3,
    NET_IF_OPER_STATUS_UNKNOWN          = 4,
    NET_IF_OPER_STATUS_DORMANT          = 5,
    NET_IF_OPER_STATUS_NOT_PRESENT      = 6,
    NET_IF_OPER_STATUS_LOWER_LAYER_DOWN = 7
  } NET_IF_OPER_STATUS, *PNET_IF_OPER_STATUS;

  typedef ULONG32 NET_IF_OBJECT_ID, *PNET_IF_OBJECT_ID;

  typedef enum _NET_IF_ADMIN_STATUS
  {
    NET_IF_ADMIN_STATUS_UP      = 1,
    NET_IF_ADMIN_STATUS_DOWN    = 2,
    NET_IF_ADMIN_STATUS_TESTING = 3
  } NET_IF_ADMIN_STATUS, *PNET_IF_ADMIN_STATUS;

#define NET_IF_OPER_STATUS_DOWN_NOT_AUTHENTICATED   0x00000001
#define NET_IF_OPER_STATUS_DOWN_NOT_MEDIA_CONNECTED 0x00000002
#define NET_IF_OPER_STATUS_DORMANT_PAUSED           0x00000004
#define NET_IF_OPER_STATUS_DORMANT_LOW_POWER        0x00000008

  typedef UINT32 NET_IF_COMPARTMENT_SCOPE, *PNET_IF_COMPARTMENT_SCOPE;

#define NET_IF_COMPARTMENT_SCOPE_UNSPECIFIED (NET_IF_COMPARTMENT_SCOPE)0
#define NET_IF_COMPARTMENT_SCOPE_ALL         ((NET_IF_COMPARTMENT_SCOPE)-1)

#define NET_IF_OID_IF_ALIAS       0x00000001
#define NET_IF_OID_COMPARTMENT_ID 0x00000002
#define NET_IF_OID_NETWORK_GUID   0x00000003
#define NET_IF_OID_IF_ENTRY       0x00000004

#define NET_SET_UNSPECIFIED_NETWORK_GUID(_pNetworkGuid)
#define NET_IS_UNSPECIFIED_NETWORK_GUID(_NetworkGuidValue)

#define NET_SITEID_UNSPECIFIED (0)
#define NET_SITEID_MAXUSER     (0x07ffffff)
#define NET_SITEID_MAXSYSTEM   (0x0fffffff)
#ifndef __WIDL__
  C_ASSERT(NET_SITEID_MAXUSER < NET_SITEID_MAXSYSTEM);
#endif

  typedef enum _NET_IF_RCV_ADDRESS_TYPE
  {
    NET_IF_RCV_ADDRESS_TYPE_OTHER        = 1,
    NET_IF_RCV_ADDRESS_TYPE_VOLATILE     = 2,
    NET_IF_RCV_ADDRESS_TYPE_NON_VOLATILE = 3
  } NET_IF_RCV_ADDRESS_TYPE, *PNET_IF_RCV_ADDRESS_TYPE;

  typedef struct _NET_IF_RCV_ADDRESS_LH
  {
    NET_IF_RCV_ADDRESS_TYPE ifRcvAddressType;
    USHORT                  ifRcvAddressLength;
    USHORT                  ifRcvAddressOffset;
  } NET_IF_RCV_ADDRESS_LH, *PNET_IF_RCV_ADDRESS_LH;

  typedef struct _NET_IF_ALIAS_LH
  {
    USHORT  ifAliasLength;
    USHORT  ifAliasOffset;
  } NET_IF_ALIAS_LH, *PNET_IF_ALIAS_LH;

  typedef union _NET_LUID_LH
  {
    ULONG64 Value;
    struct
    {
      ULONG64 Reserved     : 24;
      ULONG64 NetLuidIndex : 24;
      ULONG64 IfType       : 16;
    } Info;
  } NET_LUID_LH, *PNET_LUID_LH;

  typedef NET_IF_RCV_ADDRESS_LH  NET_IF_RCV_ADDRESS;
  typedef NET_IF_RCV_ADDRESS    *PNET_IF_RCV_ADDRESS;
  typedef NET_IF_ALIAS_LH        NET_IF_ALIAS;
  typedef NET_IF_ALIAS          *PNET_IF_ALIAS;
  typedef NET_LUID_LH            NET_LUID;
  typedef NET_LUID              *PNET_LUID;
  typedef NET_LUID               IF_LUID, *PIF_LUID;
  typedef ULONG                  NET_IFINDEX, *PNET_IFINDEX;
  typedef UINT16                 NET_IFTYPE, *PNET_IFTYPE;

#define NET_IFINDEX_UNSPECIFIED (NET_IFINDEX)(0)
#define NET_IFLUID_UNSPECIFIED  (0)

#ifndef __IF_INDEX_DEFINED__
# define __IF_INDEX_DEFINED__
#endif

  typedef NET_IFINDEX IF_INDEX, *PIF_INDEX;

  typedef enum _NET_IF_CONNECTION_TYPE
  {
    NET_IF_CONNECTION_DEDICATED = 1,
    NET_IF_CONNECTION_PASSIVE   = 2,
    NET_IF_CONNECTION_DEMAND    = 3,
    NET_IF_CONNECTION_MAXIMUM   = 4
  } NET_IF_CONNECTION_TYPE, *PNET_IF_CONNECTION_TYPE;

  typedef enum _TUNNEL_TYPE
  {
    TUNNEL_TYPE_NONE      = 0,
    TUNNEL_TYPE_OTHER     = 1,
    TUNNEL_TYPE_DIRECT    = 2,
    TUNNEL_TYPE_6TO4      = 11,
    TUNNEL_TYPE_ISATAP    = 13,
    TUNNEL_TYPE_TEREDO    = 14,
    TUNNEL_TYPE_IPHTTPS   = 15
  } TUNNEL_TYPE, *PTUNNEL_TYPE;

#define IFI_UNSPECIFIED NET_IFINDEX_UNSPECIFIED

#define NIIF_HARDWARE_INTERFACE      0x00000001
#define NIIF_FILTER_INTERFACE        0x00000002
#define NIIF_NDIS_RESERVED1          0x00000004
#define NIIF_NDIS_RESERVED2          0x00000008
#define NIIF_NDIS_RESERVED3          0x00000010
#define NIIF_NDIS_WDM_INTERFACE      0x00000020
#define NIIF_NDIS_ENDPOINT_INTERFACE 0x00000040
#define NIIF_NDIS_ISCSI_INTERFACE    0x00000080
#define NIIF_NDIS_RESERVED4          0x00000100
#define NIIF_WAN_TUNNEL_TYPE_UNKNOWN ((ULONG)(-1))

  typedef enum _NET_IF_ACCESS_TYPE
  {
    NET_IF_ACCESS_LOOPBACK             = 1,
    NET_IF_ACCESS_BROADCAST            = 2,
    NET_IF_ACCESS_POINT_TO_POINT       = 3,
    NET_IF_ACCESS_POINT_TO_MULTI_POINT = 4,
    NET_IF_ACCESS_MAXIMUM              = 5
  } NET_IF_ACCESS_TYPE, *PNET_IF_ACCESS_TYPE;

  typedef enum _NET_IF_DIRECTION_TYPE
  {
    NET_IF_DIRECTION_SENDRECEIVE,
    NET_IF_DIRECTION_SENDONLY,
    NET_IF_DIRECTION_RECEIVEONLY,
    NET_IF_DIRECTION_MAXIMUM
  } NET_IF_DIRECTION_TYPE, *PNET_IF_DIRECTION_TYPE;

  typedef enum _NET_IF_MEDIA_CONNECT_STATE
  {
    MediaConnectStateUnknown,
    MediaConnectStateConnected,
    MediaConnectStateDisconnected
  } NET_IF_MEDIA_CONNECT_STATE, *PNET_IF_MEDIA_CONNECT_STATE;

#define NET_IF_LINK_SPEED_UNKNOWN ((ULONG64)(-1))

  typedef enum _NET_IF_MEDIA_DUPLEX_STATE
  {
    MediaDuplexStateUnknown,
    MediaDuplexStateHalf,
    MediaDuplexStateFull
  } NET_IF_MEDIA_DUPLEX_STATE, *PNET_IF_MEDIA_DUPLEX_STATE;

#define NIIF_BUS_NUMBER_UNKNOWN      ((ULONG)(-1))
#define NIIF_SLOT_NUMBER_UNKNOWN     ((ULONG)(-1))
#define NIIF_FUNCTION_NUMBER_UNKNOWN ((ULONG)(-1))

  typedef struct _NET_PHYSICAL_LOCATION_LH
  {
    ULONG BusNumber;
    ULONG SlotNumber;
    ULONG FunctionNumber;
  } NET_PHYSICAL_LOCATION_LH, *PNET_PHYSICAL_LOCATION_LH;

#define IF_MAX_STRING_SIZE 256

  typedef struct _IF_COUNTED_STRING_LH
  {
    USHORT Length;
    WCHAR  String[IF_MAX_STRING_SIZE + 1];
  } IF_COUNTED_STRING_LH, *PIF_COUNTED_STRING_LH;

#define IF_MAX_PHYS_ADDRESS_LENGTH 32

  typedef struct _IF_PHYSICAL_ADDRESS_LH
  {
    USHORT Length;
    UCHAR  Address[IF_MAX_PHYS_ADDRESS_LENGTH];
  } IF_PHYSICAL_ADDRESS_LH, *PIF_PHYSICAL_ADDRESS_LH;

  typedef NET_PHYSICAL_LOCATION_LH  NET_PHYSICAL_LOCATION;
  typedef NET_PHYSICAL_LOCATION    *PNET_PHYSICAL_LOCATION;
  typedef IF_COUNTED_STRING_LH      IF_COUNTED_STRING;
  typedef IF_COUNTED_STRING        *PIF_COUNTED_STRING;
  typedef IF_PHYSICAL_ADDRESS_LH    IF_PHYSICAL_ADDRESS;
  typedef IF_PHYSICAL_ADDRESS      *PIF_PHYSICAL_ADDRESS;

  typedef enum _IF_ADMINISTRATIVE_STATE
  {
    IF_ADMINISTRATIVE_DISABLED,
    IF_ADMINISTRATIVE_ENABLED,
    IF_ADMINISTRATIVE_DEMANDDIAL,
  } IF_ADMINISTRATIVE_STATE, *PIF_ADMINISTRATIVE_STATE;

  typedef enum _IF_OPER_STATUS
  {
    IfOperStatusUp = 1,
    IfOperStatusDown,
    IfOperStatusTesting,
    IfOperStatusUnknown,
    IfOperStatusDormant,
    IfOperStatusNotPresent,
    IfOperStatusLowerLayerDown
  } IF_OPER_STATUS;

  typedef struct _NDIS_INTERFACE_INFORMATION
  {
    NET_IF_OPER_STATUS         ifOperStatus;
    ULONG                      ifOperStatusFlags;
    NET_IF_MEDIA_CONNECT_STATE MediaConnectState;
    NET_IF_MEDIA_DUPLEX_STATE  MediaDuplexState;
    ULONG                      ifMtu;
    BOOLEAN                    ifPromiscuousMode;
    BOOLEAN                    ifDeviceWakeUpEnable;
    ULONG64                    XmitLinkSpeed;
    ULONG64                    RcvLinkSpeed;
    ULONG64                    ifLastChange;
    ULONG64                    ifCounterDiscontinuityTime;
    ULONG64                    ifInUnknownProtos;
    ULONG64                    ifInDiscards;
    ULONG64                    ifInErrors;
    ULONG64                    ifHCInOctets;
    ULONG64                    ifHCInUcastPkts;
    ULONG64                    ifHCInMulticastPkts;
    ULONG64                    ifHCInBroadcastPkts;
    ULONG64                    ifHCOutOctets;
    ULONG64                    ifHCOutUcastPkts;
    ULONG64                    ifHCOutMulticastPkts;
    ULONG64                    ifHCOutBroadcastPkts;
    ULONG64                    ifOutErrors;
    ULONG64                    ifOutDiscards;
    ULONG64                    ifHCInUcastOctets;
    ULONG64                    ifHCInMulticastOctets;
    ULONG64                    ifHCInBroadcastOctets;
    ULONG64                    ifHCOutUcastOctets;
    ULONG64                    ifHCOutMulticastOctets;
    ULONG64                    ifHCOutBroadcastOctets;
    NET_IF_COMPARTMENT_ID      CompartmentId;
    ULONG                      SupportedStatistics;
  } NDIS_INTERFACE_INFORMATION, *PNDIS_INTERFACE_INFORMATION;

#ifdef __cplusplus
}
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#endif  /* _INC_IFDEF */
