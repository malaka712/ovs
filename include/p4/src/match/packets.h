/*
 * Copyright 2013-present Barefoot Networks, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * File:   packets.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_PACKETS_H
#define	OVS_MATCH_PACKETS_H 1

/* -- Called in lib/packets.h -- */
#define _ETHERNET__HEADER_LEN 14
#define _INTRINSIC_METADATA_HEADER_LEN 7
#define VALID_HEADER_LEN 1

/* -- Called in lib/packets.h -- */
#define OVS_HDR_STRUCTS \
    OVS_PACKED( \
    struct _ethernet__header { \
        struct ethernet__dstAddr_t ethernet__dstAddr; \
        struct ethernet__srcAddr_t ethernet__srcAddr; \
        ovs_be16 ethernet__etherType; \
    }); \
    BUILD_ASSERT_DECL(_ETHERNET__HEADER_LEN == sizeof(struct _ethernet__header)); \
    \
    OVS_PACKED( \
    struct _ethernet__padded_header { \
        struct _ethernet__header hdr; \
        uint8_t pad[2]; \
    }); \
    BUILD_ASSERT_DECL( \
        _ETHERNET__HEADER_LEN+2 == sizeof(struct _ethernet__padded_header)); \
    \
    OVS_PACKED( \
    struct _intrinsic_metadata_header { \
        uint8_t intrinsic_metadata_mcast_grp_egress_rid; \
        ovs_be16 intrinsic_metadata_mcast_hash; \
        ovs_be32 intrinsic_metadata_lf_field_list; \
    }); \
    BUILD_ASSERT_DECL(_INTRINSIC_METADATA_HEADER_LEN == sizeof(struct _intrinsic_metadata_header)); \
    \
    OVS_PACKED( \
    struct _intrinsic_metadata_padded_header { \
        struct _intrinsic_metadata_header hdr; \
        uint8_t pad[1]; \
    }); \
    BUILD_ASSERT_DECL( \
        _INTRINSIC_METADATA_HEADER_LEN+1 == sizeof(struct _intrinsic_metadata_padded_header)); \
    \
    OVS_PACKED( \
    struct valid_header { \
        uint8_t _ethernet__valid; \
    }); \
    BUILD_ASSERT_DECL(VALID_HEADER_LEN == sizeof(struct valid_header)); \
    \
    OVS_PACKED( \
    struct valid_padded_header { \
        struct valid_header hdr; \
        uint8_t pad[7]; \
    }); \
    BUILD_ASSERT_DECL( \
        VALID_HEADER_LEN+7 == sizeof(struct valid_padded_header)); \
    \

/* -- Called in lib/packets.h -- */
#define OVS_HDR_DECLS \
    void packet_set__ethernet_( \
        struct ethernet__dstAddr_t ethernet__dstAddr, \
        struct ethernet__srcAddr_t ethernet__srcAddr, \
        ovs_be16 ethernet__etherType, \
        struct dp_packet *packet); \
    \
    void packet_set_valid( \
        uint8_t _ethernet__valid, \
        struct dp_packet *packet); \
    \

/* -- Called in lib/packets.c -- */
#define OVS_HDR_DEFS \
    void packet_set__ethernet_( \
        struct ethernet__dstAddr_t ethernet__dstAddr, \
        struct ethernet__srcAddr_t ethernet__srcAddr, \
        ovs_be16 ethernet__etherType, \
        struct dp_packet *packet) \
    { \
        struct _ethernet__header *_ethernet_ = &packet->_ethernet_; \
        \
        _ethernet_->ethernet__dstAddr = ethernet__dstAddr; \
        _ethernet_->ethernet__srcAddr = ethernet__srcAddr; \
        _ethernet_->ethernet__etherType = ethernet__etherType; \
    } \
    \
    void packet_set_valid( \
        uint8_t _ethernet__valid, \
        struct dp_packet *packet) \
    { \
        packet->_ethernet__valid = _ethernet__valid; \
    } \
    \

#endif	/* OVS_MATCH_PACKETS_H */
