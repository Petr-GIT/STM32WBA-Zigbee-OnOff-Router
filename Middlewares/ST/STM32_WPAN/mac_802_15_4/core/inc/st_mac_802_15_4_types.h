/**
  ******************************************************************************
  * @file    st_mac_802_15_4_types.h
  * @author  MCD Application Team
  * @brief   Header for mac interface types
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef _ST_MAC_802_15_4_TYPES_H_
#define _ST_MAC_802_15_4_TYPES_H_

#include <stdint.h>

#include "st_mac_802_15_4_config.h"


typedef uint8_t  MAC_Status_t;
typedef uint8_t  MAC_handle;

#ifndef UNUSED
#define UNUSED(x)(void)(x)
#endif /* UNUSED */

#define MAC_SUCCESS                   ((uint8_t)0x00)
#define MAC_ERROR                     ((uint8_t)0x01)
#define MAC_NOT_IMPLEMENTED_STATUS    ((uint8_t)0x02)
#define MAC_NOT_SUPPORTED_STATUS      ((uint8_t)0x03)
#define MAC_HW_NOT_SUPPORTED_STATUS   ((uint8_t)0x04)
#define MAC_UNDEFINED_STATUS          ((uint8_t)0x05)
#define MAC_HW_BUSY                   ((uint8_t)0x06)
#define MAC_INVALID_PARAMETER         ((uint8_t)0x07)

/* MAC RAW specific error */
#define MAC_UNEXPECTED_RADIO_STATE    ((uint8_t)0x10)
#define MAC_INVALID_STACK             ((uint8_t)0x11)

/** @brief  Defines the value for NULL */
#define g_NULL_c                       0 //( void* ) ( 0 )

/** @brief  Defines the value for Reset */
#define g_RESET_c                      0x00

/** @brief  Defines the length of the 64 - bit Address or IEEE MAC Address */
#define g_EXTENDED_ADDRESS_LENGTH_c    0x08

/** @brief  Defines the length of the 16 - bit Short Address */
#define g_SHORT_ADDRESS_LENGTH_c       0x02

/** @brief  Defines the length of the 16 - bit Short PAN ID */
#define g_SHORT_PAN_ID_LENGTH_c        0x02

/** @brief  Defines the length for parameters of 8 bytes */
#define g_EIGHT_BYTE_LENGTH_c          0x08

/** @brief  Defines the broadcast PAN ID */
#define g_BROADCAST_PAN_ID_c           0xFFFF

/** @brief  Defines the broadcast PAN ID */
#define g_BROADCAST_ADDRESS_c          0xFFFF

/** @brief  Defines the broadcast PAN ID */
#define g_INVALID_ADDRESS_c            0xFFFF

/** @brief  Defines the broadcast PAN ID */
#define g_INVALID_PAN_ID_c             0xFFFF

/** @brief  Defines Invalid index */
#define g_INVALID_INDEX_c              0xFF

/** @brief  Defines Invalid value */
#define g_INVALID_VALUE_c              0xFF

/** @brief Short address is not allocated */
#define g_ADDRESS_NOT_ALLOCATED_c      0xFFFE

/** @brief Index to CMD Id field in MAC Cmd Frames */
#define g_IDX_TO_CMD_ID_c      0x00

/** @brief  tab size to stock PAN coordiantor when beacon is received */
#define NB_PAN_BEACON_RECEIVED      10U

/** @brief  Defines the type used to handle addresses. Addresses are either short (2 bytes)
    or extended (8 bytes) */
typedef union {
    /*! Short address */
    uint8_t a_short_addr[2];
    /*! Extended address */
    uint8_t a_extend_addr[8];
} MAC_addr_t;

typedef struct{
    uint8_t GTSCharacteristics_fields;
}MAC_GTSCharacteristics_t;


/** @brief Define the type used to IEs header. 
    Size in 1 byte and list pointer for all elements */
typedef struct {
    /** length of header IEs on 7 bits + ElementID + Type of header IEs, Type=0 */
    uint16_t hdr_ie_length_elementID_Type;
    /** content of header IEs */
    uint8_t hdr_ie_content[MAX_HDR_IE_CONTENT]; // MAX IE size is CSL IE=6bytes 
} ST_MAC_hdr_ie;

/** @brief Define the type used to IEs payload. 
    Size in 1 byte and list pointer for all elements */
typedef struct {
    /** length of payload IEs on 10 bits + GroupID + Type of payload IEs Type=1 */
    uint16_t pyld_ie_length_groupID_Type;
    /** content of payload IEs */
    uint8_t pyld_ie_content[MAX_PYLD_IE_CONTENT]; // Size equals to MAX_ZIGBEE_EBR_IE_LEN, LL define
} ST_MAC_pyld_ie;


/******************************************************************************/
/** @brief  Defines a structure for MAC PAN Descriptor which contains the
 network details of the device from which the beacon is received */

typedef struct {
    /*! PAN identifier of the coordinator */
    uint8_t a_coord_PAN_id[2];
    /*! Coordinator addressing mode */
    uint8_t coord_addr_mode;
    /*! The current logical channel occupied by the network */
    uint8_t logical_channel;
    /*! Coordinator address */
    MAC_addr_t coord_addr;
    /*! The current channel page occupied by the network */
    uint8_t channel_page;
    /*! PAN coordinator is accepting GTS requests or not */
    uint8_t gts_permit;
    /*! Superframe specification as specified in the received beacon frame */
    uint8_t a_superframe_spec[2];
    /*! The time at which the beacon frame was received, in symbols */
    uint8_t a_time_stamp[4];
    /*! The LQI at which the network beacon was received */
    uint8_t link_quality;
    /*! Security level purportedly used by the received beacon frame */
    uint8_t security_level;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_PAN_Desc_t;


/** @brief Defines the structure for  MLME ASSOCIATE Request which will be used
 by the application to request an association */

typedef struct {
    /*! The logical channel on which to attempt association */
    uint8_t channel_number;
    /*! The channel page on which to attempt association */
    uint8_t channel_page;
    /*! Coordinator addressing mode used */
    uint8_t coord_addr_mode;
    /*! Operational capabilities of the associating device */
    uint8_t capability_information;
    /*! The identifier of the PAN with which to associate*/
    uint8_t a_coord_PAN_id[2];
    /*! The security level to be used */
    uint8_t security_level;
    /*! The mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! The originator of the key to be used */
    uint8_t a_key_source[8];
    /*! Coordinator address */
    MAC_addr_t coord_address;
    /*! The index of the key to be used */
    uint8_t key_index;
} ST_MAC_associateReq_t;

/******************************************************************************/

/** @brief Defines the structure for  MLME DISASSOCIATE Request which will be
 used by the application to request an disassociation */

typedef struct {
    /*! Device addressing mode used */
    uint8_t device_addr_mode;
    /*! The identifier of the PAN of the device */
    uint8_t a_device_PAN_id[2];
    /*! The reason for the disassociation */
    uint8_t disassociate_reason;
    /*! Device address */
    MAC_addr_t device_address;
    /*! TRUE if the disassociation notification command is to be sent indirectly */
    uint8_t tx_Indirect;
    /*! The security level to be used */
    uint8_t security_level;
    /*! The mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! The index of the key to be used */
    uint8_t key_index;
    /*! The originator of the key to be used */
    uint8_t a_key_source[8];
} ST_MAC_disassociateReq_t;

/** @brief Defines the structure for  MLME GET Request which will be
 used by the application to request a PIB Value */

typedef struct {
    /*! The name of the PIB attribute to read*/
    uint8_t PIB_attribute;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_getReq_t;

/** @brief Defines the structure for  MLME GTS Request which will be
 used by the application to request and maintain GTSs */

typedef struct {

    /*! The characteristics of the GTS*/
    MAC_GTSCharacteristics_t GTS_characteristics;
    /*! The security level to be used */
    uint8_t security_level;
    /*! The mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! The index of the key to be used */
    uint8_t key_index;
    /*! The originator of the key to be used */
    uint8_t a_key_source[8];
} ST_MAC_gtsReq_t;


/** @brief  Defines the structure for MLME RESET Request which allows the
 application to request that the MLME of the MAC layer performs a
 reset operation */

typedef struct {
    /*! MAC PIB attributes are set to their default values or not during reset */
    uint8_t set_default_PIB;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_resetReq_t;


/******************************************************************************/
/** @brief  Defines the structure for MLME RX ENABLE Request which allows the
 application to request that the receiver is either enabled
 for a finite period of time or disabled */

typedef struct {
    /*! The requested operation can be deferred or not */
    uint8_t defer_permit;
    /*!Configure the transceiver to Rx with ranging for a
    value of RANGING_ON or to not enable ranging for
    RANGING_OFF */
    uint8_t ranging_Rx_control;
    /*! Number of symbols measured before the receiver is to be enabled or
    disabled */
    uint8_t a_Rx_on_time[3];
    /*! Number of symbols for which the receiver is to be enabled */
    uint8_t a_Rx_on_duration[3];
} ST_MAC_rxEnableReq_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME SCAN Request which is used to
 initiate a channel scan over a given list of channels */

typedef struct {
    /*! The type of scan to be performed */
    uint8_t scan_type;
    /*! The time spent on scanning each channel */
    uint8_t scan_duration;
    /*! Channel page on which to perform the scan */
    uint8_t channel_page;
    /*! Security level to be used */
    uint8_t security_level;
    /*! Indicate which channels are to be scanned */
    uint8_t a_scan_channels[4];
    /*! Originator of the key to be used */
    uint8_t a_key_source[8];
    /*! Structure to header IE List*/
    ST_MAC_hdr_ie hdr_ie_list[NB_HDR_IES];
    /*! Structure to payload IE List*/
    ST_MAC_pyld_ie pyld_ie_list[NB_PYLD_IES];
    /*! Set to TRUE if the sequence number is suppressed in the frame */
    uint8_t scan_seq_sup;
    /*! Mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! Index of the key to be used */
    uint8_t key_index;
} ST_MAC_scanReq_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME SET Request which is used to
 attempt to write the given value to the indicated PIB attribute */

typedef struct {
    /*! The pointer to the Value of the PIB attribute to set*/
    uint8_t *PIB_attribute_valuePtr;
    /*! The name of the PIB attribute to set*/
    uint8_t PIB_attribute;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_setReq_t;


/******************************************************************************/
/** @brief Defines the structure for MLME START Request which is used by the
 FFDs to initiate a new PAN or to begin using a new superframe
 configuration */

typedef struct {
    /*! PAN identifier to be used by the device */
    uint8_t a_PAN_id[2];
    /*! Logical channel on which to begin */
    uint8_t channel_number;
    /*! Channel page on which to begin */
    uint8_t channel_page;
    /*! Time at which to begin transmitting beacons */
    uint8_t a_start_time[4];
    /*! Indicates how often the beacon is to be transmitted */
    uint8_t beacon_order;
    /*! Length of the active portion of the superframe */
    uint8_t superframe_order;
    /*! Indicates whether the device is a PAN coordinator or not */
    uint8_t PAN_coordinator;
    /*! Indicates if the receiver of the beaconing device is disabled or not */
    uint8_t battery_life_extension;
    /*! Indicates if the coordinator realignment command is to be transmitted */
    uint8_t coord_realignment;
    /*! Indicates if the coordinator realignment command is to be transmitted */
    uint8_t coord_realign_security_level;
    /*! Mode used to identify the key to be used */
    uint8_t coord_realign_key_id_mode;
    /*! Index of the key to be used */
    uint8_t coord_realign_key_index;
    /*! Originator of the key to be used*/
    uint8_t a_coord_realign_key_source[8];
    /*! Security level to be used for beacon frames */
    uint8_t beacon_security_level;
    /*! Mode used to identify the key to be used */
    uint8_t beacon_key_id_mode;
    /*! Index of the key to be used */
    uint8_t beacon_key_index;
    /*! Originator of the key to be used */
    uint8_t a_beacon_key_source[8];
    /*!< structure to header IE List*/
    ST_MAC_hdr_ie hdr_ie_list[NB_HDR_IES]; 
    /*!< structure to payload IE List*/
    ST_MAC_pyld_ie pyld_ie_list[NB_PYLD_IES];   
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[1];
} ST_MAC_startReq_t;


/******************************************************************************/
/** @brief  Defines the structure for MLME POLL Request which prompts the
 device to request data from the coordinator */

typedef struct {
    /*! Addressing mode of the coordinator */
    uint8_t coord_addr_mode;
    /*! Security level to be used */
    uint8_t security_level;
    /*! Mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! Index of the key to be used*/
    uint8_t key_index;
    /*! Coordinator address */
    MAC_addr_t coord_address;
    /*! Originator of the key to be used */
    uint8_t a_key_source[8];
    /*! PAN identifier of the coordinator */
    uint8_t a_coord_PAN_id[2];
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_pollReq_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME DPS Request which allows the next
 higher layer to request that the PHY utilize a given pair of preamble codes
 for a single use pending expiration of the DPSIndexDuration */

typedef struct {
    /*! The index value for the transmitter */
    uint8_t Tx_DPS_index;
    /*! The index value for the receiver */
    uint8_t Rx_DPS_index;
    /*! The number of symbols for which the transmitter and
    receiver will utilize the respective DPS indices */
    uint8_t DPS_index_duration;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[1];
} ST_MAC_dpsReq_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME SOUNDING request primitive which is
used by the next higher layer to request that the PHY respond with channel
sounding information */

/* Empty struct soundingReq_t */
typedef struct {
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[4];
} ST_MAC_soundingReq_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME CALIBRATE request primitive which
used  to obtain the results of a ranging calibration request from an RDEV*/

/* Empty struct MAC_calibrateReq_t */
typedef struct {
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[4];
} ST_MAC_calibrateReq_t;


/** @brief Defines the structure for MCPS DATA Request which will be used for
 MAC data related requests from the application */

typedef struct {
    /*! Source addressing mode used */
    uint8_t src_addr_mode;
    /*! Destination addressing mode used */
    uint8_t dst_addr_mode;
    /*! Destination PAN ID  */
    uint8_t a_dst_PAN_id[2];
    /*! Destination address */
    MAC_addr_t dst_address;
    /*! The number of octets contained in the MSDU */
    uint8_t msdu_length;
    /*! The handle associated with the MSDU to be transmitted  */
    uint8_t msdu_handle;
    /*! The ACK transmission options for the MSDU */
    uint8_t ack_Tx;
    /*!TRUE if a GTS is to be used for transmission.
    FALSE indicates that the CAP will be used */
    uint8_t GTS_Tx;
    /*! The Pending Bit transmission options for the MSDU */
    uint8_t indirect_Tx;
    /*! The security level to be used */
    uint8_t security_level;
    /*! The mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! The index of the key to be used */
    uint8_t key_index;
    /*! The originator of the key to be used */
    uint8_t a_key_source[8];
    /*! 2011 - The pulse repetition value*/
    uint8_t UWBPRF;
    /*! 2011 - The ranging configuration */
    uint8_t ranging;
    /*! 2011 - The preamble symbol repetitions */
    uint8_t UWB_preamble_symbol_repetitions;
    /*! 2011 - Indicates the data rate */
    uint8_t data_rate;
    /*! The handle associated with the MSDU to be transmitted  */
    /*! Must always be at the end of this structure */
    uint8_t *msduPtr;
} ST_MAC_dataReq_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME Get-Power-Information-Table Request primitive 
 which prompts the device to request the Power Control Information entry for the link pair */

typedef struct {
  /*! Short address of the link pair to transmit the packet to */
  uint16_t short_address;
  /*! Extended (IEEE) address of the link pair to transmit the packet to */
  uint8_t ieee_address[8];
  /*! Byte Stuffing to keep 32 bit alignment*/
  uint8_t a_stuffing[2];
} ST_MAC_getPwrInfoTableReq_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME Set-Power-Information-Table Request primitive
 which prompts the device to add the Power Control Information entry for the link pair */

typedef struct {
  /*! Short address of the link pair to transmit the packet to */
  uint16_t short_address;
  /*! Extended (IEEE) address of the link pair to transmit the packet to */
  uint8_t ieee_address[8];
  /*! Tx Power Level */
  int8_t tx_pwr_level;
  /*! Last RSSI Level */
  int8_t last_rssi_level;
  /*! Network Negotiated */
  uint8_t nwk_negociated;
  /*! Byte Stuffing to keep 32 bit alignment*/
  uint8_t a_stuffing[3];
} ST_MAC_setPwrInfoTableReq_t;

/******************************************************************************/

/** @brief Defines the structure for MCPS PURGE Request which will be used by
 the application to purge an MSDU from the transaction
 queue */

typedef struct {
    /*! The handle associated with the MSDU to be purged from the transaction
     queue */
    uint8_t msdu_handle;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_purgeReq_t;

/** @brief Defines the structure for MLME BEACON Request primitive
 which send a beacon manually */

typedef struct {
  /*! The beacon type NormalBeacon=0, EnhancedBeacon=1 */
  uint8_t beacon_type;
  /*! The logical channel on which the device lost synchronization or to which it was realigned */
  uint8_t channel_number;
  /*! The channel page on which the device lost synchronization or to which it was realigned */
  uint8_t channel_page;
  /*! Length of the active portion of the superframe */
  uint8_t superframe_order;
  /*!< structure to header IE List*/
  ST_MAC_hdr_ie hdr_ie_list[NB_HDR_IES]; 
  /*!< structure to payload IE List*/
  ST_MAC_pyld_ie pyld_ie_list[NB_PYLD_IES];   
  /*! The beacon security level to be used */
  uint8_t beacon_security_level;
  /*! The mode used to identify the beacon key to be used */
  uint8_t beacon_key_id_mode;
  /*! The originator of the beacon key to be used */
  uint8_t beacon_key_source[8];
  /*! The index of the beacon key to be used */
  uint8_t beacon_key_index;
  /*! source address mode */
  uint8_t src_addr_mode;
  /*! Destination addressing mode used */
  uint8_t dst_addr_mode;
  /*! Destination address */
  MAC_addr_t dst_address;
  /*! BSN Suppression */
  uint8_t BSN_suppression;
  /*! Byte Stuffing to keep 32 bit alignment*/
  uint8_t a_stuffing[1];
} ST_MAC_beaconReq_t;

/******************************************************************************/

/** @brief  Defines the structure for MLME ASSOCIATE Response which is used to
 initiate a response to an MLME-ASSOCIATE.indication*/

typedef struct {
    /*! Extended address of the device requesting association */
    uint8_t a_device_address[8];
    /*! 16-bit short device address allocated by the coordinator on successful
     association */
    uint8_t a_assoc_short_address[2];
    /*! Status of the association attempt */
    uint8_t status;
    /*! Security level to be used */
    uint8_t security_level;
    /*! The originator of the key to be used */
    uint8_t a_key_source[8];
        /*! The mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! The index of the key to be used */
    uint8_t key_index;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_associateRes_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME ORPHAN Response which is used by the
 application layer of the coordinator to respond to the MLME ORPHAN
 Indication */

typedef struct {
    /*! Extended address of the orphaned device */
    uint8_t a_orphan_address[8];
    /*! Short address allocated to the orphaned device */
    uint8_t a_short_address[2];
    /*! If the orphaned device is associated with the coordinator or not */
    uint8_t associated_member;
    /*! Security level to be used */
    uint8_t security_level;
    /*! Originator of the key to be used */
    uint8_t a_key_source[8];
    /*! Mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! Index of the key to be used */
    uint8_t key_index;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_orphanRes_t;

/******************************************************************************/

/** @brief Defines a structure for MLME ASSOCIATE Confirm which is used to
 inform the application of the initiating device whether its
 request to associate was successful or unsuccessful */

typedef struct {
    /*! Short address allocated by the coordinator on successful association */
    uint8_t a_assoc_short_address[2];
    /*! Status of the association attempt*/
    uint8_t status;
    /*! The security level used */
    uint8_t security_level;
    /*! The originator of the key */
    uint8_t a_key_source[8];
    /*! The mode used to identify the key */
    uint8_t key_id_mode;
    /*! The index of the key */
    uint8_t key_index;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_associateCnf_t;


/******************************************************************************/

/** @brief Defines the structure for  MLME DISASSOCIATE Confirm which will be
 used to send disassociation Confirmation to the application. */

 typedef struct {
    /*! Status of the disassociation attempt*/
    uint8_t status;
    /*! Device addressing mode used */
    uint8_t device_addr_mode;
    /*! The identifier of the PAN of the device */
    uint8_t a_device_PAN_id[2];
    /*! Device address */
    MAC_addr_t device_address;
} ST_MAC_disassociateCnf_t;

/******************************************************************************/
/** @brief Defines the structure for  MLME GET Confirm which requests information
about a given PIB attribute */


typedef struct {
    /*! Status of the GET attempt*/
    uint8_t status;
    /*! The name of the PIB attribute attempted to read*/
    uint8_t PIB_attribute;
    /*! The length of the PIB attribute Value return*/
    uint8_t PIB_attribute_value_len;
    /*! The pointer to the value of the PIB attribute attempted to read*/
    uint8_t PIB_attribute_value[1];
} ST_MAC_getCnf_t;

/******************************************************************************/
/** @brief Defines the structure for  MLME GTS Confirm which eports the results
of a request to allocate a new GTS or to deallocate an existing GTS */

typedef struct {
    /*! The characteristics of the GTS*/
    uint8_t GTS_characteristics;
    /*!The status of the GTS request*/
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_gtsCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME RESET Confirm which is used to report
 the results of the reset operation */

typedef struct {
    /*! The result of the reset operation */
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_resetCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME RX ENABLE Confirm which is used to
 report the results of the attempt to enable or disable the receiver*/

typedef struct {
    /*! Result of the request to enable or disable the receiver */
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_rxEnableCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME SCAN Confirm which is used to report
 the result of the channel scan request */

typedef struct {
    /*! Status of the scan request */
    uint8_t status;
    /*! The type of scan performed */
    uint8_t scan_type;
    /*! Channel page on which the scan was performed */
    uint8_t channel_page;
    /*! Channels given in the request which were not scanned */
    uint8_t a_unscanned_channels[4];
    /*! Number of elements returned in the appropriate result lists */
    uint8_t result_list_size;
    /*! List of energy measurements */
    uint8_t a_energy_detect_list[g_MAX_ED_SCAN_RESULTS_SUPPORTED_c];
    /*! List of PAN descriptors */
    ST_MAC_PAN_Desc_t a_PAN_descriptor_list[g_MAX_PAN_DESC_SUPPORTED_c];
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_scanCnf_t;


/******************************************************************************/
/** @brief  Defines the structure for MLME SET Confirm which reports the results
of an attempt to write a value to a PIB attribute */

typedef struct {
     /*! The result of the set operation */
    uint8_t status;
    /*! The name of the PIB attribute that was written.*/
    uint8_t PIB_attribute;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_setCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME START Confirm which is used to
 report the results of the attempt to start using a new superframe
 configuration */

typedef struct {
    /*!Result of the attempt to start using an updated superframe configuration*/
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_startCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME POLL Confirm which is used to report
 the result of a request to poll the coordinator for data */

typedef struct {
    /*! The status of the data request */
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_pollCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME DPS Confirm which  reports the
results of the attempt to enable or disable the DPS */

typedef struct {
    /*! The status of the DPS request */
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_dpsCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME SOUNDING Confirm which  reports the
result of a request to the PHY to provide channel sounding information */

typedef struct {
    /*! Results of the sounding measurement*/
    uint8_t a_sounding_list[g_MAX_SOUNDING_LIST_SUPPORTED_c];
    /*! The status of the attempt to return sounding data*/
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_soundingCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME CALIBRATE Confirm which reports the
result of a request to the PHY to provide internal propagation path information.*/

typedef struct {
    /*! The status of the attempt to return sounding data*/
    uint8_t status;
    /*! A count of the propagation time from the ranging counter to
    the transmit antenna */
    uint32_t cal_Tx_rmaker_offset;
    /*! A count of the propagation time from the
    receive antenna to the ranging counter */
    uint32_t cal_Rx_rmaker_offset;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_calibrateCnf_t;

/******************************************************************************/
/** @brief Defines the structure for MCPS DATA Confirm which will be used for
 reporting the results of MAC data related requests from the
 application */

typedef struct {
    /*! The handle associated with the MSDU being confirmed */
    uint8_t msdu_handle;
     /*! The time, in symbols, at which the data were transmitted */
    uint8_t a_time_stamp[4];
    /*! ranging status */
    uint8_t ranging_received;
    /*! The status of the last MSDU transmission */
    uint8_t status;
    /*! time units corresponding to an RMARKER at the antenna at the
    beginning of a ranging exchange */
    uint32_t ranging_counter_start;
    /*!time units corresponding to an RMARKER at the antenna at the
    end of a ranging exchange */
    uint32_t ranging_counter_stop;
    /*! time units in a message exchange over which the tracking offset
    was measured */
    uint32_t ranging_tracking_interval;
    /*! time units slipped or advanced by the radio tracking system */
    uint32_t ranging_offset;
    /*! The FOM characterizing the ranging measurement */
    uint8_t ranging_FOM;
} ST_MAC_dataCnf_t;

/******************************************************************************/
/** @brief Defines the structure for MCPS PURGE Confirm which will be used by
 the  MAC to notify the application of the status of its request
 to purge an MSDU from the transaction queue */

typedef struct {
    /*! Handle associated with the MSDU requested to be purged from the
     transaction queue */
    uint8_t msdu_handle;
    /*! The status of the request */
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
} ST_MAC_purgeCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME Get-Power-Information-Table Confirm primitive
 which is used to inform the application of the initiating device about the status and
 information requested */

typedef struct {
  /*! Status used to indicate if an entry was found for the pair requested */
  uint8_t status;
  /*! Short address of the link pair to transmit the packet to */
  uint16_t short_address;
  /*! Extended (IEEE) address of the link pair to transmit the packet to */
  uint8_t ieee_address[8];
  /*! Tx Power Level */
  int8_t tx_pwr_level;
  /*! Last RSSI Level */
  int8_t last_rssi_level;
  /*! Network Negotiated */
  uint8_t nwk_negociated;
  /*! Byte Stuffing to keep 32 bit alignment*/
  uint8_t a_stuffing[2];
} ST_MAC_getPwrInfoTableCnf_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME Set-Power-Information-Table Confirm primitive
 which is used to inform the application of the initiating device about the status of
 the REQUEST */

typedef struct {
  /*! The result of the reset operation */
  uint8_t status;
  /*! Byte Stuffing to keep 32 bit alignment*/
  uint8_t a_stuffing[3];
} ST_MAC_setPwrInfoTableCnf_t;


/** @brief Defines the structure for MLME BEACON Confirm which will be used for
 reporting the results of MAC beacon related requests from the
 application */
typedef struct {
    /*! The status of the request */
    uint8_t status;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[3];
} ST_MAC_beaconCnf_t;

/******************************************************************************/
/** @brief Defines the structure for MLME ASSOCIATE Indication which will be
 used by the MAC to indicate the reception of an association request
 command */


typedef struct {
    /*! Extended address of the device requesting association */
    uint8_t a_device_address[8];
    /*! Operational capabilities of the device requesting association */
    uint8_t capability_information;
    /*! Security level purportedly used by the received MAC command frame*/
    uint8_t security_level;
    /*! The mode used to identify the key used by the originator of frame */
    uint8_t key_id_mode;
    /*! Index of the key used by the originator of the received frame */
    uint8_t key_index;
     /*! The originator of the key used by the originator of the received frame */
    uint8_t a_key_source[8];
} ST_MAC_associateInd_t;

/******************************************************************************/
/** @brief Defines the structure for  MLME DISASSOCIATE indication which will be
 used to send disassociation indication to the application. */

typedef struct {
    /*! Extended address of the device requesting association */
    uint8_t a_device_address[8];
    /*! The reason for the disassociation */
    uint8_t disassociate_reason;
    /*! The security level to be used */
    uint8_t security_level;
    /*! The mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! The index of the key to be used */
    uint8_t key_index;
    /*! The originator of the key to be used */
    uint8_t a_key_source[8];
} ST_MAC_disassociateInd_t;


/******************************************************************************/
/** @brief   Defines a structure for MLME BEACON NOTIIFY Indication which is
 used to send parameters contained within a beacon frame received
 by the MAC to the application */

typedef struct {
    /*! The PAN Descriptor for the received beacon */
    ST_MAC_PAN_Desc_t PAN_descriptor;
    /*! The list of addresses of the devices for
    which the beacon source has data*/
    MAC_addr_t a_addr_list[g_MAX_PENDING_ADDRESS_c];
    /*! Beacon Sequence Number */
    uint8_t BSN;
    /*! The beacon pending address specification */
    uint8_t pend_addr_spec;
    /*! The beacon type NormalBeacon=0, EnhancedBeacon=1 */
    uint8_t beacon_type;
    /** header IEs  */
    ST_MAC_hdr_ie hdr_ie_list[NB_HDR_IES];
    /** Payload IEs */
    ST_MAC_pyld_ie pyld_ie_list[NB_PYLD_IES];
    /*! Number of octets contained in the beacon payload of the beacon frame */
    uint8_t sdu_length;
    /*! The set of octets comprising the beacon payload to be transferred
    from the MAC sublayer entity to the next higher layer */
    uint8_t sduPtr[1];
} ST_MAC_beaconNotifyInd_t;


/******************************************************************************/
/** @brief  Defines the structure for MLME COMM STATUS Indication which is used
 by the MAC to indicate a communications status */

typedef struct {
    /*! The 16-bit PAN identifier of the device from which the frame was
    received or to which the frame was being sent */
    uint8_t a_PAN_id[2];
    /*! Source addressing mode */
    uint8_t src_addr_mode;
    /*! Destination addressing mode */
    uint8_t dst_addr_mode;
    /*! Source address */
    MAC_addr_t src_address;
    /*! Destination address */
    MAC_addr_t dst_address;
    /*! The communications status */
    uint8_t status;
    /*! Security level to be used */
    uint8_t security_level;
    /*! Mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! Index of the key to be used */
    uint8_t key_index;
    /*! Originator of the key to be used */
    uint8_t a_key_source[8];
} ST_MAC_commStatusInd_t;


/******************************************************************************/
/** @brief  Defines the structure for MLME GTS Indication indicates that a GTS
has been allocated or that a previously allocated GTS has been deallocated */

typedef struct {
    /*! The short address of the device that has been
    allocated or deallocated a GTS */
    uint8_t a_device_address[2];
    /*! The characteristics of the GTS */
    MAC_GTSCharacteristics_t GTS_characteristics;
    /*! Security level to be used */
    uint8_t security_level;
    /*! Mode used to identify the key to be used */
    uint8_t key_id_mode;
    /*! Index of the key to be used */
    uint8_t key_index;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[2];
    /*! Originator of the key to be used */
    uint8_t a_key_source[8];
} ST_MAC_GtsInd_t;

/******************************************************************************/
/** @brief   Defines the structure for MLME ORPHAN Indication which is used by
 the coordinator to notify the application of the presence of
 an orphaned device */

typedef struct {
    /*! Extended address of the orphaned device */
    uint8_t a_orphan_address[8];
    /*! Originator of the key used by the originator of the received frame */
    uint8_t a_key_source[8];
    /*! Security level purportedly used by the received MAC command frame */
    uint8_t security_level;
    /*! Mode used to identify the key used by originator of received frame */
    uint8_t key_id_mode;
    /*! Index of the key used by the originator of the received frame */
    uint8_t key_index;
    /*! Byte Stuffing to keep 32 bit alignment*/
    uint8_t a_stuffing[1];
} ST_MAC_orphanInd_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME SYNC LOSS Indication which is used
 by the MAC to indicate the loss of synchronization with the
 coordinator */

typedef struct {
    /*! The PAN identifier with which the device lost synchronization or to
     which it was realigned */
    uint8_t a_PAN_id[2];
    /*! The reason that synchronization was lost */
    uint8_t loss_reason;
    /*! The logical channel on which the device lost synchronization or to which
     it was realigned */
    uint8_t channel_number;
    /*! The channel page on which the device lost synchronization or to which it
     was realigned */
    uint8_t channel_page;
    /*! The security level used by the received MAC frame */
    uint8_t security_level;
    /*! Mode used to identify the key used by originator of received frame */
    uint8_t key_id_mode;
    /*! Index of the key used by the originator of the received frame */
    uint8_t key_index;
    /*! Originator of the key used by the originator of the received frame */
    uint8_t a_key_source[8];
} ST_MAC_syncLoss_t;

/******************************************************************************/
/** @brief  Defines the structure for MLME DPS Indication which indicates the
expiration of the DPSIndexDuration and the resetting of the DPS values
in the PHY */

/* Empty struct dpsInd_t */
typedef struct {
    uint8_t a_stuffing[4];
} ST_MAC_dpsInd_t;

/******************************************************************************/
/** @brief Defines the structure for MCPS DATA Indication which will be used
 for indicating the transfer of a data packet by the MAC */

typedef struct {
    /*! Source addressing mode used */
    uint8_t src_addr_mode;
    /*! Source PAN ID  */
    uint8_t a_src_PAN_id[2];
    /*! Source address */
    MAC_addr_t src_address;
    /*! Destination addressing mode used */
    uint8_t dst_addr_mode;
    /*! Destination PAN ID  */
    uint8_t a_dst_PAN_id[2];
    /*! Destination address */
    MAC_addr_t dst_address;
    /*! The number of octets contained in the MSDU being indicated */
    uint8_t msdu_length;
    /*!LQI value measured during reception of the MPDU*/
    uint8_t mpdu_link_quality;
    /*! The data sequence number of the received data frame */
    uint8_t DSN;
    /*! The time, in symbols, at which the data were received */
    uint8_t a_time_stamp[4];
    /*! The security level purportedly used by the received data frame */
    uint8_t security_level;
    /*! Mode used to identify the key used by originator of received frame */
    uint8_t key_id_mode;
    /*! The originator of the key */
    uint8_t a_key_source[8];
    /*! The index of the key */
    uint8_t key_index;
    /*!The pulse repetition value of the received PPDU*/
    uint8_t UWBPRF;
    /*! The preamble symbol repetitions of the UWB PHY frame */
    uint8_t UWB_preamble_symbol_repetitions;
    /*! Indicates the data rate*/
    uint8_t data_rate;
    uint8_t ranging_received;
    uint32_t ranging_counter_start;
    /*! time units corresponding to an RMARKER at the antenna at the end of a ranging exchange, */
    uint32_t ranging_counter_stop;
    /*!time units in a message exchange over which the tracking offset was measured*/
    uint32_t ranging_tracking_interval;
    /*! time units slipped or advanced by the radio tracking system */
    uint32_t ranging_offset;
    /*! The FOM characterizing the ranging measurement*/
    uint8_t ranging_FOM;
    /*! The Received Signal Strength Indicator measured*/
    int8_t rssi;
    int8_t Stuffing; // Keep Alignmenta
    /*! Pointer to the set of octets forming the MSDU being indicated */
    uint8_t msdu[1];
} ST_MAC_dataInd_t;

/******************************************************************************/
/** @brief Defines the structure for MLME POLL Indication which will be used
 for indicating the Data Request reception to upper layer as defined in
 Zigbee r22 - D.8.2*/

typedef struct {
  /*! addressing mode used */
  uint8_t addr_mode; // Valid Range: 0x02 � 0x03
  /*! Poll requester address */
  MAC_addr_t request_address;
  /*! Byte Stuffing to keep 32 bit alignment*/
  uint8_t a_stuffing[3];
} ST_MAC_pollInd_t;


/** @brief Defines the structure for MLME BEACONREQUEST Indication which will be used
 for indicating a beacon is received by the MAC */

typedef struct {
  /*! Source address */
  uint8_t src_address[8];
  /*! header IEs from beacon request frame */
  ST_MAC_hdr_ie hdr_ie_list[NB_HDR_IES];
  /*! Payload IEs from beacon request frame */
  ST_MAC_pyld_ie pyld_ie_list[NB_PYLD_IES];
  /*!  Source PAN ID*/
  uint8_t a_device_PAN_id[2];
  /*! Type of beacon frame */
  uint8_t beacon_type;
  /*! source address mode */
  uint8_t src_addr_mode;
  /*! Byte Stuffing to keep 32 bit alignment*/
  uint8_t a_stuffing[2];
} ST_MAC_beaconReqInd_t;


/** @brief Defines the structure for list_PAN_Coord tab, allows to stock all beacons received from PAN coordinator. */
typedef struct {
  /*! PAN identifier of the coordinator */
  uint8_t a_coord_PAN_id[2];
  /*! Coordinator addressing mode */
  uint8_t coord_addr_mode;
  /*! The current logical channel occupied by the network */
  uint8_t logical_channel;
  /*! Coordinator address */
  MAC_addr_t coord_addr;
} ST_MAC_PAN_COORD_t;

/** @brief Defines the structure for regroup table of ST_MAC_PAN_COORD_t and indice_PAN_Coord */
typedef struct {
  ST_MAC_PAN_COORD_t list_PAN_Coord[NB_PAN_BEACON_RECEIVED];
  uint8_t indice_PAN_Coord;
} ST_MAC_PAN_Coord_Table_t;

/*Callback Typedef */
/******************************************************************************/
/* Confirmation */
/******************************************************************************/

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
 MLME Associate Confirmation*/
typedef MAC_Status_t (* ST_MAC_MLMEAssociateCnfCbPtr) ( const ST_MAC_associateCnf_t * pAssociateCnf );

 /******************************************************************************/
/** @brief Defines the callback function Pointer for Pointer type for
MLME Disassociate Confirmation*/
typedef MAC_Status_t (* ST_MAC_MLMEDisassociateCnfCbPtr) ( const  ST_MAC_disassociateCnf_t * pDisassociateCnf);

/******************************************************************************/
/** @brief Defines the callback function Pointer for Pointer type for
MLME Get Confirmation*/
typedef MAC_Status_t (* ST_MAC_MLMEGetCnfCbPtr) ( const ST_MAC_getCnf_t * pGetCnf);

/******************************************************************************/
/** @brief Defines the callback function Pointer for Pointer type for
 MLME GTS Confirmation*/
typedef MAC_Status_t (* ST_MAC_MLMEGtsCnfCbPtr) ( const ST_MAC_gtsCnf_t * pGtsCnf);

/******************************************************************************/
/** @brief Defines the callback function for Pointer type for
MLME RESET Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMEResetCnfCbPtr) ( const  ST_MAC_resetCnf_t * pResetCnf );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME RXEnable Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMERxEnableCnfCbPtr) ( const ST_MAC_rxEnableCnf_t * pRxEnable );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME SCAN Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMEScanCnfCbPtr) ( const  ST_MAC_scanCnf_t * pScanCnf);

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME SET Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMESetCnfCbPtr) ( const ST_MAC_setCnf_t * pSetCnf );

/******************************************************************************/
/** @brief Defines the callback functionPointer type for
MLME START Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMEStartCnfCbPtr) ( const ST_MAC_startCnf_t * pStartCnf);

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME POLL Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMEPollCnfCbPtr) ( const ST_MAC_pollCnf_t * pPollCnf );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME DPS Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMEDpsCnfCbPtr) ( const ST_MAC_dpsCnf_t * pDpsCnf  );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME SOUNDING Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMESoundingCnfCbPtr) ( const ST_MAC_soundingCnf_t * pSoudingCnf);

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME CALIBRATE Confirmation*/
typedef MAC_Status_t (*ST_MAC_MLMECalibrateCnfCbPtr) ( const ST_MAC_calibrateCnf_t * pCalibrateCnf);

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MCPS DATA Confirmation*/
typedef MAC_Status_t (* ST_MAC_MCPSDataCnfCbPtr) ( const ST_MAC_dataCnf_t * pDataCnf );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MCPS PURGE Confirmation*/
typedef MAC_Status_t (* ST_MAC_MCPSPurgeCnfCbPtr) ( const ST_MAC_purgeCnf_t * pPurgeCnf );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME Beacon confirm*/
typedef MAC_Status_t (* ST_MAC_MLMEBeaconCnfCbPtr) ( const ST_MAC_beaconCnf_t * pBeaconCnf );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME GetPwrInfoTable confirm*/
typedef MAC_Status_t (* ST_MAC_MLMEGetPwrInfoTableCnfCbPtr) ( const ST_MAC_getPwrInfoTableCnf_t * pGetPwrInfoTableCnf );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME SetPwrInfoTable confirm*/
typedef MAC_Status_t (* ST_MAC_MLMESetPwrInfoTableCnfCbPtr) ( const ST_MAC_setPwrInfoTableCnf_t * pSetPwrInfoTableCnf );

/******************************************************************************/
/* Indication */
/******************************************************************************/

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME Associate Indication*/
/******************************************************************************/
typedef MAC_Status_t (* ST_MAC_MLMEAssociateIndCbPtr) ( const ST_MAC_associateInd_t * pAssociateInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME Disassociate Indication*/
typedef MAC_Status_t (* ST_MAC_MLMEDisassociateIndCbPtr) ( const ST_MAC_disassociateInd_t * pDisassociateInd);

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME Beacon Notification Indication*/
typedef MAC_Status_t (* ST_MAC_MLMEBeaconNotifyIndCbPtr) ( const ST_MAC_beaconNotifyInd_t * pBeaconNotifyInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME Communication Status Indication*/
typedef MAC_Status_t (* ST_MAC_MLMECommStatusIndCbPtr) ( const ST_MAC_commStatusInd_t * pCommStatusInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME GTS Indication*/
typedef MAC_Status_t (* ST_MAC_MLMEGtsIndCbPtr) ( const ST_MAC_GtsInd_t * pGtsInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME Orphan Indication*/
typedef MAC_Status_t (* ST_MAC_MLMEOrphanIndCbPtr) ( const ST_MAC_orphanInd_t * pOrphanInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME SYNC LOSS Indication*/
typedef MAC_Status_t (* ST_MAC_MLMESyncLossIndCbPtr) ( const ST_MAC_syncLoss_t * pSyncLoss );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME DPS Indication*/
typedef MAC_Status_t (* ST_MAC_MLMEDpsIndCbPtr) ( const ST_MAC_dpsInd_t * pDdsInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MCPS DATA Indication*/
typedef MAC_Status_t (* ST_MAC_MCPSDataIndCbPtr) ( const ST_MAC_dataInd_t * pDataInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME POLL Indication*/
typedef MAC_Status_t (* ST_MAC_MLMEPollIndCbPtr) ( const ST_MAC_pollInd_t * pPollInd );

/******************************************************************************/
/** @brief Defines the callback function Pointer type for
MLME BeaconReq Indication*/
typedef MAC_Status_t (* ST_MAC_MLMEBeaconReqIndCbPtr) ( const ST_MAC_beaconReqInd_t * pBeaconReqInd );

/**
  * @}
  */

/**@addtogroup  STM32WB55_MAC
  * @{
  */

/******************************************************************************/
/** @brief Defines callback init structure to be set by NWK upper layer before
 MAC Initialisation */

typedef struct {
  ST_MAC_MLMEAssociateCnfCbPtr       mlmeAssociateCnfCb;
  ST_MAC_MLMEAssociateIndCbPtr       mlmeAssociateIndCb;
  ST_MAC_MLMEBeaconNotifyIndCbPtr    mlmeBeaconNotifyIndCb;
  ST_MAC_MLMECalibrateCnfCbPtr       mlmeCalibrateCnfCb;
  ST_MAC_MLMECommStatusIndCbPtr      mlmeCommStatusIndCb;
  ST_MAC_MLMEDisassociateCnfCbPtr    mlmeDisassociateCnfCb;
  ST_MAC_MLMEDisassociateIndCbPtr    mlmeDisassociateIndCb;
  ST_MAC_MLMEDpsCnfCbPtr             mlmeDpsCnfCb;
  ST_MAC_MLMEDpsIndCbPtr             mlmeDpsIndCb;
  ST_MAC_MLMEGetCnfCbPtr             mlmeGetCnfCb;
  ST_MAC_MLMEGtsCnfCbPtr             mlmeGtsCnfCb;
  ST_MAC_MLMEGtsIndCbPtr             mlmeGtsIndCb;
  ST_MAC_MLMEOrphanIndCbPtr          mlmeOrphanIndCb;
  ST_MAC_MLMEPollCnfCbPtr            mlmePollCnfCb;
  ST_MAC_MLMEResetCnfCbPtr           mlmeResetCnfCb;
  ST_MAC_MLMERxEnableCnfCbPtr        mlmeRxEnableCnfCb;
  ST_MAC_MLMEScanCnfCbPtr            mlmeScanCnfCb;
  ST_MAC_MLMESetCnfCbPtr             mlmeSetCnfCb;
  ST_MAC_MLMESoundingCnfCbPtr        mlmeSoundingCnfCb;
  ST_MAC_MLMEStartCnfCbPtr           mlmeStartCnfCb;
  ST_MAC_MLMESyncLossIndCbPtr        mlmeSyncLossIndCb;
  ST_MAC_MCPSDataIndCbPtr            mcpsDataIndCb;
  ST_MAC_MCPSDataCnfCbPtr            mcpsDataCnfCb;
  ST_MAC_MCPSPurgeCnfCbPtr           mcpsPurgeCnfCb;
  ST_MAC_MLMEPollIndCbPtr            mlmePollIndCb;
  ST_MAC_MLMEBeaconReqIndCbPtr       mlmeBeaconReqIndCb;
  ST_MAC_MLMEBeaconCnfCbPtr          mlmeBeaconCnfCb;
  ST_MAC_MLMEGetPwrInfoTableCnfCbPtr mlmeGetPwrInfoTableCnfCb;
  ST_MAC_MLMESetPwrInfoTableCnfCbPtr mlmeSetPwrInfoTableCnfCb;
} ST_MAC_callbacks_t;

/**
  * @}
  */

#endif /* _ST_MAC_802_15_4_TYPES_H_ */