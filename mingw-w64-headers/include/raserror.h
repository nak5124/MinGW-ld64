/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _RASERROR_H_
#define _RASERROR_H_

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)

#define RASBASE 600
#define SUCCESS 0

#define PENDING (RASBASE+0)
#define ERROR_INVALID_PORT_HANDLE (RASBASE+1)
#define ERROR_PORT_ALREADY_OPEN (RASBASE+2)
#define ERROR_BUFFER_TOO_SMALL (RASBASE+3)
#define ERROR_WRONG_INFO_SPECIFIED (RASBASE+4)
#define ERROR_PORT_NOT_CONNECTED (RASBASE+6)
#define ERROR_DEVICE_DOES_NOT_EXIST (RASBASE+8)
#define ERROR_DEVICETYPE_DOES_NOT_EXIST (RASBASE+9)
#define ERROR_BUFFER_INVALID (RASBASE+10)
#define ERROR_ROUTE_NOT_ALLOCATED (RASBASE+12)
#define ERROR_PORT_NOT_FOUND (RASBASE+15)
#define ERROR_ASYNC_REQUEST_PENDING (RASBASE+16)
#define ERROR_ALREADY_DISCONNECTING (RASBASE+17)
#define ERROR_PORT_NOT_OPEN (RASBASE+18)
#define ERROR_PORT_DISCONNECTED (RASBASE+19)
#define ERROR_CANNOT_OPEN_PHONEBOOK (RASBASE+21)
#define ERROR_CANNOT_LOAD_PHONEBOOK (RASBASE+22)
#define ERROR_CANNOT_FIND_PHONEBOOK_ENTRY (RASBASE+23)
#define ERROR_CANNOT_WRITE_PHONEBOOK (RASBASE+24)
#define ERROR_CORRUPT_PHONEBOOK (RASBASE+25)
#define ERROR_KEY_NOT_FOUND (RASBASE+27)
#define ERROR_DISCONNECTION (RASBASE+28)
#define ERROR_REMOTE_DISCONNECTION (RASBASE+29)
#define ERROR_HARDWARE_FAILURE (RASBASE+30)
#define ERROR_USER_DISCONNECTION (RASBASE+31)
#define ERROR_INVALID_SIZE (RASBASE+32)
#define ERROR_PORT_NOT_AVAILABLE (RASBASE+33)
#define ERROR_UNKNOWN (RASBASE+35)
#define ERROR_WRONG_DEVICE_ATTACHED (RASBASE+36)
#define ERROR_REQUEST_TIMEOUT (RASBASE+38)
#define ERROR_AUTH_INTERNAL (RASBASE+45)
#define ERROR_RESTRICTED_LOGON_HOURS (RASBASE+46)
#define ERROR_ACCT_DISABLED (RASBASE+47)
#define ERROR_PASSWD_EXPIRED (RASBASE+48)
#define ERROR_NO_DIALIN_PERMISSION (RASBASE+49)
#define ERROR_FROM_DEVICE (RASBASE+51)
#define ERROR_UNRECOGNIZED_RESPONSE (RASBASE+52)
#define ERROR_MACRO_NOT_FOUND (RASBASE+53)
#define ERROR_MACRO_NOT_DEFINED (RASBASE+54)
#define ERROR_MESSAGE_MACRO_NOT_FOUND (RASBASE+55)
#define ERROR_DEFAULTOFF_MACRO_NOT_FOUND (RASBASE+56)
#define ERROR_FILE_COULD_NOT_BE_OPENED (RASBASE+57)
#define ERROR_DEVICENAME_TOO_LONG (RASBASE+58)
#define ERROR_DEVICENAME_NOT_FOUND (RASBASE+59)
#define ERROR_NO_RESPONSES (RASBASE+60)
#define ERROR_NO_COMMAND_FOUND (RASBASE+61)
#define ERROR_WRONG_KEY_SPECIFIED (RASBASE+62)
#define ERROR_UNKNOWN_DEVICE_TYPE (RASBASE+63)
#define ERROR_ALLOCATING_MEMORY (RASBASE+64)
#define ERROR_PORT_NOT_CONFIGURED (RASBASE+65)
#define ERROR_DEVICE_NOT_READY (RASBASE+66)
#define ERROR_READING_INI_FILE (RASBASE+67)
#define ERROR_NO_CONNECTION (RASBASE+68)
#define ERROR_BAD_USAGE_IN_INI_FILE (RASBASE+69)
#define ERROR_READING_SECTIONNAME (RASBASE+70)
#define ERROR_READING_DEVICETYPE (RASBASE+71)
#define ERROR_READING_DEVICENAME (RASBASE+72)
#define ERROR_READING_USAGE (RASBASE+73)
#define ERROR_LINE_BUSY (RASBASE+76)
#define ERROR_VOICE_ANSWER (RASBASE+77)
#define ERROR_NO_ANSWER (RASBASE+78)
#define ERROR_NO_CARRIER (RASBASE+79)
#define ERROR_NO_DIALTONE (RASBASE+80)
#define ERROR_AUTHENTICATION_FAILURE (RASBASE+91)
#define ERROR_PORT_OR_DEVICE (RASBASE+92)
#define ERROR_NOT_BINARY_MACRO (RASBASE+93)
#define ERROR_DCB_NOT_FOUND (RASBASE+94)
#define ERROR_STATE_MACHINES_NOT_STARTED (RASBASE+95)
#define ERROR_STATE_MACHINES_ALREADY_STARTED (RASBASE+96)
#define ERROR_PARTIAL_RESPONSE_LOOPING (RASBASE+97)
#define ERROR_UNKNOWN_RESPONSE_KEY (RASBASE+98)
#define ERROR_RECV_BUF_FULL (RASBASE+99)
#define ERROR_CMD_TOO_LONG (RASBASE+100)
#define ERROR_UNSUPPORTED_BPS (RASBASE+101)
#define ERROR_UNEXPECTED_RESPONSE (RASBASE+102)
#define ERROR_INTERACTIVE_MODE (RASBASE+103)
#define ERROR_BAD_CALLBACK_NUMBER (RASBASE+104)
#define ERROR_INVALID_AUTH_STATE (RASBASE+105)
#define ERROR_X25_DIAGNOSTIC (RASBASE+107)
#define ERROR_ACCT_EXPIRED (RASBASE+108)
#define ERROR_CHANGING_PASSWORD (RASBASE+109)
#define ERROR_OVERRUN (RASBASE+110)
#define ERROR_RASMAN_CANNOT_INITIALIZE (RASBASE+111)
#define ERROR_NO_ACTIVE_ISDN_LINES (RASBASE+113)
#define ERROR_IP_CONFIGURATION (RASBASE+116)
#define ERROR_NO_IP_ADDRESSES (RASBASE+117)
#define ERROR_PPP_TIMEOUT (RASBASE+118)
#define ERROR_PPP_NO_PROTOCOLS_CONFIGURED (RASBASE+120)
#define ERROR_PPP_NO_RESPONSE (RASBASE+121)
#define ERROR_PPP_INVALID_PACKET (RASBASE+122)
#define ERROR_PHONE_NUMBER_TOO_LONG (RASBASE+123)
#define ERROR_IPXCP_DIALOUT_ALREADY_ACTIVE (RASBASE+126)
#define ERROR_NO_IP_RAS_ADAPTER (RASBASE+128)
#define ERROR_SLIP_REQUIRES_IP (RASBASE+129)
#define ERROR_PROTOCOL_NOT_CONFIGURED (RASBASE+131)
#define ERROR_PPP_NOT_CONVERGING (RASBASE+132)
#define ERROR_PPP_CP_REJECTED (RASBASE+133)
#define ERROR_PPP_LCP_TERMINATED (RASBASE+134)
#define ERROR_PPP_REQUIRED_ADDRESS_REJECTED (RASBASE+135)
#define ERROR_PPP_NCP_TERMINATED (RASBASE+136)
#define ERROR_PPP_LOOPBACK_DETECTED (RASBASE+137)
#define ERROR_PPP_NO_ADDRESS_ASSIGNED (RASBASE+138)
#define ERROR_CANNOT_USE_LOGON_CREDENTIALS (RASBASE+139)
#define ERROR_TAPI_CONFIGURATION (RASBASE+140)
#define ERROR_NO_LOCAL_ENCRYPTION (RASBASE+141)
#define ERROR_NO_REMOTE_ENCRYPTION (RASBASE+142)
#define ERROR_BAD_PHONE_NUMBER (RASBASE+149)
#define ERROR_SCRIPT_SYNTAX (RASBASE+152)
#define ERROR_HANGUP_FAILED (RASBASE+153)
#define ERROR_BUNDLE_NOT_FOUND (RASBASE+154)
#define ERROR_CANNOT_DO_CUSTOMDIAL (RASBASE+155)
#define ERROR_DIAL_ALREADY_IN_PROGRESS (RASBASE+156)
#define ERROR_RASAUTO_CANNOT_INITIALIZE (RASBASE+157)
#define ERROR_NO_SMART_CARD_READER (RASBASE+164)
#define ERROR_SHARING_ADDRESS_EXISTS (RASBASE+165)
#define ERROR_NO_CERTIFICATE (RASBASE+166)
#define ERROR_SHARING_MULTIPLE_ADDRESSES (RASBASE+167)
#define ERROR_FAILED_TO_ENCRYPT (RASBASE+168)
#define ERROR_BAD_ADDRESS_SPECIFIED (RASBASE+169)
#define ERROR_CONNECTION_REJECT (RASBASE+170)
#define ERROR_CONGESTION (RASBASE+171)
#define ERROR_INCOMPATIBLE (RASBASE+172)
#define ERROR_NUMBERCHANGED (RASBASE+173)
#define ERROR_TEMPFAILURE (RASBASE+174)
#define ERROR_BLOCKED (RASBASE+175)
#define ERROR_DONOTDISTURB (RASBASE+176)
#define ERROR_OUTOFORDER (RASBASE+177)
#define ERROR_UNABLE_TO_AUTHENTICATE_SERVER (RASBASE+178)
#define ERROR_INVALID_FUNCTION_FOR_ENTRY (RASBASE+180)
#define ERROR_SHARING_RRAS_CONFLICT (RASBASE+182)
#define ERROR_SHARING_NO_PRIVATE_LAN (RASBASE+183)
#define ERROR_NO_DIFF_USER_AT_LOGON (RASBASE+184)
#define ERROR_NO_REG_CERT_AT_LOGON (RASBASE+185)
#define ERROR_OAKLEY_NO_CERT (RASBASE+186)
#define ERROR_OAKLEY_AUTH_FAIL (RASBASE+187)
#define ERROR_OAKLEY_ATTRIB_FAIL (RASBASE+188)
#define ERROR_OAKLEY_GENERAL_PROCESSING (RASBASE+189)
#define ERROR_OAKLEY_NO_PEER_CERT (RASBASE+190)
#define ERROR_OAKLEY_NO_POLICY (RASBASE+191)
#define ERROR_OAKLEY_TIMED_OUT (RASBASE+192)
#define ERROR_OAKLEY_ERROR (RASBASE+193)
#define ERROR_UNKNOWN_FRAMED_PROTOCOL (RASBASE+194)
#define ERROR_WRONG_TUNNEL_TYPE (RASBASE+195)
#define ERROR_UNKNOWN_SERVICE_TYPE (RASBASE+196)
#define ERROR_CONNECTING_DEVICE_NOT_FOUND (RASBASE+197)
#define ERROR_NO_EAPTLS_CERTIFICATE (RASBASE+198)
#define ERROR_SHARING_HOST_ADDRESS_CONFLICT (RASBASE+199)
#define ERROR_AUTOMATIC_VPN_FAILED (RASBASE+200)
#define ERROR_VALIDATING_SERVER_CERT (RASBASE+201)
#define ERROR_READING_SCARD (RASBASE+202)
#define ERROR_INVALID_PEAP_COOKIE_CONFIG (RASBASE+203)
#define ERROR_INVALID_PEAP_COOKIE_USER (RASBASE+204)
#define ERROR_INVALID_MSCHAPV2_CONFIG (RASBASE+205)
#define ERROR_VPN_GRE_BLOCKED (RASBASE+206)
#define ERROR_VPN_DISCONNECT (RASBASE+207)
#define ERROR_VPN_REFUSED (RASBASE+208)
#define ERROR_VPN_TIMEOUT (RASBASE+209)
#define ERROR_VPN_BAD_CERT (RASBASE+210)
#define ERROR_VPN_BAD_PSK (RASBASE+211)
#define ERROR_SERVER_POLICY (RASBASE+212)
#define ERROR_BROADBAND_ACTIVE (RASBASE+213)
#define ERROR_BROADBAND_NO_NIC (RASBASE+214)
#define ERROR_BROADBAND_TIMEOUT (RASBASE+215)
#define ERROR_FEATURE_DEPRECATED (RASBASE+216)
#define ERROR_CANNOT_DELETE (RASBASE+217)
#define ERROR_PEAP_CRYPTOBINDING_INVALID (RASBASE+223)
#define ERROR_PEAP_CRYPTOBINDING_NOTRECEIVED (RASBASE+224)
#define ERROR_EAPTLS_CACHE_CREDENTIALS_INVALID (RASBASE+226)
#define ERROR_IPSEC_SERVICE_STOPPED (RASBASE+227)

#define ERROR_INVALID_VPNSTRATEGY (RASBASE+225)
#define ERROR_IDLE_TIMEOUT (RASBASE+228)
#define ERROR_LINK_FAILURE (RASBASE+229)
#define ERROR_USER_LOGOFF (RASBASE+230)
#define ERROR_FAST_USER_SWITCH (RASBASE+231)
#define ERROR_HIBERNATION (RASBASE+232)
#define ERROR_SYSTEM_SUSPENDED (RASBASE+233)
#define ERROR_RASMAN_SERVICE_STOPPED (RASBASE+234)
#define ERROR_INVALID_SERVER_CERT (RASBASE+235)
#define ERROR_NOT_NAP_CAPABLE (RASBASE+236)
#define ERROR_INVALID_TUNNELID (RASBASE+237)
#define ERROR_UPDATECONNECTION_REQUEST_IN_PROCESS (RASBASE+238)
#define ERROR_PROTOCOL_ENGINE_DISABLED (RASBASE+239)
#define ERROR_INTERNAL_ADDRESS_FAILURE (RASBASE+240)
#define ERROR_FAILED_CP_REQUIRED (RASBASE+241)
#define ERROR_TS_UNACCEPTABLE (RASBASE+242)
#define ERROR_MOBIKE_DISABLED (RASBASE+243)
#define ERROR_CANNOT_INITIATE_MOBIKE_UPDATE (RASBASE+244)
#define ERROR_PEAP_SERVER_REJECTED_CLIENT_TLV (RASBASE+245)
#define ERROR_INVALID_PREFERENCES (RASBASE+246)
#define ERROR_EAPTLS_SCARD_CACHE_CREDENTIALS_INVALID (RASBASE+247)
#define ERROR_SSTP_COOKIE_SET_FAILURE (RASBASE + 248)
#define ERROR_INVALID_PEAP_COOKIE_ATTRIBUTES (RASBASE+249)
#define ERROR_EAP_METHOD_NOT_INSTALLED (RASBASE+250)
#define ERROR_EAP_METHOD_DOES_NOT_SUPPORT_SSO (RASBASE+251)
#define ERROR_EAP_METHOD_OPERATION_NOT_SUPPORTED (RASBASE+252)
#define ERROR_EAP_USER_CERT_INVALID (RASBASE+253)
#define ERROR_EAP_USER_CERT_EXPIRED (RASBASE+254)
#define ERROR_EAP_USER_CERT_REVOKED (RASBASE+255)
#define ERROR_EAP_USER_CERT_OTHER_ERROR (RASBASE+256)
#define ERROR_EAP_SERVER_CERT_INVALID (RASBASE+257)
#define ERROR_EAP_SERVER_CERT_EXPIRED (RASBASE+258)
#define ERROR_EAP_SERVER_CERT_REVOKED (RASBASE+259)
#define ERROR_EAP_SERVER_CERT_OTHER_ERROR (RASBASE+260)
#define ERROR_EAP_USER_ROOT_CERT_NOT_FOUND (RASBASE+261)
#define ERROR_EAP_USER_ROOT_CERT_INVALID (RASBASE+262)
#define ERROR_EAP_USER_ROOT_CERT_EXPIRED (RASBASE+263)
#define ERROR_EAP_SERVER_ROOT_CERT_NOT_FOUND (RASBASE+264)
#define ERROR_EAP_SERVER_ROOT_CERT_INVALID (RASBASE+265)
#define ERROR_EAP_SERVER_ROOT_CERT_NAME_REQUIRED (RASBASE+266)
#define ERROR_PEAP_IDENTITY_MISMATCH (RASBASE+267)
#define ERROR_DNSNAME_NOT_RESOLVABLE (RASBASE+268)
#define ERROR_EAPTLS_PASSWD_INVALID (RASBASE+269)
#define ERROR_IKEV2_PSK_INTERFACE_ALREADY_EXISTS (RASBASE+270)

#define RASBASEEND (RASBASE+270)

#endif
#endif
