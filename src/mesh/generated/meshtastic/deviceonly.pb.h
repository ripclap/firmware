/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_MESHTASTIC_MESHTASTIC_DEVICEONLY_PB_H_INCLUDED
#define PB_MESHTASTIC_MESHTASTIC_DEVICEONLY_PB_H_INCLUDED
#include <pb.h>
#include "meshtastic/channel.pb.h"
#include "meshtastic/mesh.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* TODO: REPLACE */
typedef enum _meshtastic_ScreenFonts {
    /* TODO: REPLACE */
    meshtastic_ScreenFonts_FONT_SMALL = 0,
    /* TODO: REPLACE */
    meshtastic_ScreenFonts_FONT_MEDIUM = 1,
    /* TODO: REPLACE */
    meshtastic_ScreenFonts_FONT_LARGE = 2
} meshtastic_ScreenFonts;

/* Struct definitions */
/* This message is never sent over the wire, but it is used for serializing DB
 state to flash in the device code
 FIXME, since we write this each time we enter deep sleep (and have infinite
 flash) it would be better to use some sort of append only data structure for
 the receive queue and use the preferences store for the other stuff */
typedef struct _meshtastic_DeviceState {
    /* Read only settings/info about this node */
    bool has_my_node;
    meshtastic_MyNodeInfo my_node;
    /* My owner info */
    bool has_owner;
    meshtastic_User owner;
    /* TODO: REPLACE */
    pb_size_t node_db_count;
    meshtastic_NodeInfo node_db[80];
    /* Received packets saved for delivery to the phone */
    pb_size_t receive_queue_count;
    meshtastic_MeshPacket receive_queue[1];
    /* We keep the last received text message (only) stored in the device flash,
 so we can show it on the screen.
 Might be null */
    bool has_rx_text_message;
    meshtastic_MeshPacket rx_text_message;
    /* A version integer used to invalidate old save files when we make
 incompatible changes This integer is set at build time and is private to
 NodeDB.cpp in the device code. */
    uint32_t version;
    /* Used only during development.
 Indicates developer is testing and changes should never be saved to flash. */
    bool no_save;
    /* Some GPSes seem to have bogus settings from the factory, so we always do one factory reset. */
    bool did_gps_reset;
} meshtastic_DeviceState;

/* The on-disk saved channels */
typedef struct _meshtastic_ChannelFile {
    /* The channels our node knows about */
    pb_size_t channels_count;
    meshtastic_Channel channels[8];
    /* A version integer used to invalidate old save files when we make
 incompatible changes This integer is set at build time and is private to
 NodeDB.cpp in the device code. */
    uint32_t version;
} meshtastic_ChannelFile;

typedef PB_BYTES_ARRAY_T(2048) meshtastic_OEMStore_oem_icon_bits_t;
typedef PB_BYTES_ARRAY_T(32) meshtastic_OEMStore_oem_aes_key_t;
/* This can be used for customizing the firmware distribution. If populated,
 show a secondary bootup screen with cuatom logo and text for 2.5 seconds. */
typedef struct _meshtastic_OEMStore {
    /* The Logo width in Px */
    uint32_t oem_icon_width;
    /* The Logo height in Px */
    uint32_t oem_icon_height;
    /* The Logo in xbm bytechar format */
    meshtastic_OEMStore_oem_icon_bits_t oem_icon_bits;
    /* Use this font for the OEM text. */
    meshtastic_ScreenFonts oem_font;
    /* Use this font for the OEM text. */
    char oem_text[40];
    /* The default device encryption key, 16 or 32 byte */
    meshtastic_OEMStore_oem_aes_key_t oem_aes_key;
} meshtastic_OEMStore;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _meshtastic_ScreenFonts_MIN meshtastic_ScreenFonts_FONT_SMALL
#define _meshtastic_ScreenFonts_MAX meshtastic_ScreenFonts_FONT_LARGE
#define _meshtastic_ScreenFonts_ARRAYSIZE ((meshtastic_ScreenFonts)(meshtastic_ScreenFonts_FONT_LARGE+1))



#define meshtastic_OEMStore_oem_font_ENUMTYPE meshtastic_ScreenFonts


/* Initializer values for message structs */
#define meshtastic_DeviceState_init_default      {false, meshtastic_MyNodeInfo_init_default, false, meshtastic_User_init_default, 0, {meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default, meshtastic_NodeInfo_init_default}, 0, {meshtastic_MeshPacket_init_default}, false, meshtastic_MeshPacket_init_default, 0, 0, 0}
#define meshtastic_ChannelFile_init_default      {0, {meshtastic_Channel_init_default, meshtastic_Channel_init_default, meshtastic_Channel_init_default, meshtastic_Channel_init_default, meshtastic_Channel_init_default, meshtastic_Channel_init_default, meshtastic_Channel_init_default, meshtastic_Channel_init_default}, 0}
#define meshtastic_OEMStore_init_default         {0, 0, {0, {0}}, _meshtastic_ScreenFonts_MIN, "", {0, {0}}}
#define meshtastic_DeviceState_init_zero         {false, meshtastic_MyNodeInfo_init_zero, false, meshtastic_User_init_zero, 0, {meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero, meshtastic_NodeInfo_init_zero}, 0, {meshtastic_MeshPacket_init_zero}, false, meshtastic_MeshPacket_init_zero, 0, 0, 0}
#define meshtastic_ChannelFile_init_zero         {0, {meshtastic_Channel_init_zero, meshtastic_Channel_init_zero, meshtastic_Channel_init_zero, meshtastic_Channel_init_zero, meshtastic_Channel_init_zero, meshtastic_Channel_init_zero, meshtastic_Channel_init_zero, meshtastic_Channel_init_zero}, 0}
#define meshtastic_OEMStore_init_zero            {0, 0, {0, {0}}, _meshtastic_ScreenFonts_MIN, "", {0, {0}}}

/* Field tags (for use in manual encoding/decoding) */
#define meshtastic_DeviceState_my_node_tag       2
#define meshtastic_DeviceState_owner_tag         3
#define meshtastic_DeviceState_node_db_tag       4
#define meshtastic_DeviceState_receive_queue_tag 5
#define meshtastic_DeviceState_rx_text_message_tag 7
#define meshtastic_DeviceState_version_tag       8
#define meshtastic_DeviceState_no_save_tag       9
#define meshtastic_DeviceState_did_gps_reset_tag 11
#define meshtastic_ChannelFile_channels_tag      1
#define meshtastic_ChannelFile_version_tag       2
#define meshtastic_OEMStore_oem_icon_width_tag   1
#define meshtastic_OEMStore_oem_icon_height_tag  2
#define meshtastic_OEMStore_oem_icon_bits_tag    3
#define meshtastic_OEMStore_oem_font_tag         4
#define meshtastic_OEMStore_oem_text_tag         5
#define meshtastic_OEMStore_oem_aes_key_tag      6

/* Struct field encoding specification for nanopb */
#define meshtastic_DeviceState_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  my_node,           2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  owner,             3) \
X(a, STATIC,   REPEATED, MESSAGE,  node_db,           4) \
X(a, STATIC,   REPEATED, MESSAGE,  receive_queue,     5) \
X(a, STATIC,   OPTIONAL, MESSAGE,  rx_text_message,   7) \
X(a, STATIC,   SINGULAR, UINT32,   version,           8) \
X(a, STATIC,   SINGULAR, BOOL,     no_save,           9) \
X(a, STATIC,   SINGULAR, BOOL,     did_gps_reset,    11)
#define meshtastic_DeviceState_CALLBACK NULL
#define meshtastic_DeviceState_DEFAULT NULL
#define meshtastic_DeviceState_my_node_MSGTYPE meshtastic_MyNodeInfo
#define meshtastic_DeviceState_owner_MSGTYPE meshtastic_User
#define meshtastic_DeviceState_node_db_MSGTYPE meshtastic_NodeInfo
#define meshtastic_DeviceState_receive_queue_MSGTYPE meshtastic_MeshPacket
#define meshtastic_DeviceState_rx_text_message_MSGTYPE meshtastic_MeshPacket

#define meshtastic_ChannelFile_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, MESSAGE,  channels,          1) \
X(a, STATIC,   SINGULAR, UINT32,   version,           2)
#define meshtastic_ChannelFile_CALLBACK NULL
#define meshtastic_ChannelFile_DEFAULT NULL
#define meshtastic_ChannelFile_channels_MSGTYPE meshtastic_Channel

#define meshtastic_OEMStore_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   oem_icon_width,    1) \
X(a, STATIC,   SINGULAR, UINT32,   oem_icon_height,   2) \
X(a, STATIC,   SINGULAR, BYTES,    oem_icon_bits,     3) \
X(a, STATIC,   SINGULAR, UENUM,    oem_font,          4) \
X(a, STATIC,   SINGULAR, STRING,   oem_text,          5) \
X(a, STATIC,   SINGULAR, BYTES,    oem_aes_key,       6)
#define meshtastic_OEMStore_CALLBACK NULL
#define meshtastic_OEMStore_DEFAULT NULL

extern const pb_msgdesc_t meshtastic_DeviceState_msg;
extern const pb_msgdesc_t meshtastic_ChannelFile_msg;
extern const pb_msgdesc_t meshtastic_OEMStore_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define meshtastic_DeviceState_fields &meshtastic_DeviceState_msg
#define meshtastic_ChannelFile_fields &meshtastic_ChannelFile_msg
#define meshtastic_OEMStore_fields &meshtastic_OEMStore_msg

/* Maximum encoded size of messages (where known) */
#define meshtastic_ChannelFile_size              638
#define meshtastic_DeviceState_size              21800
#define meshtastic_OEMStore_size                 2140

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
