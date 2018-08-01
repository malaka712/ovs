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
 * File:   odp-execute.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_ODP_EXECUTE_H
#define	OVS_MATCH_ODP_EXECUTE_H 1

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_SET_ACTION_FUNCS \
    static void \
    odp_set__ethernet_(struct dp_packet *packet, const struct ovs_key__ethernet_ *key, \
            const struct ovs_key__ethernet_ *mask) \
    { \
        struct _ethernet__header *_ethernet_ = &packet->_ethernet_; \
        \
        struct ethernet__dstAddr_t ethernet__dstAddr; \
        apply_mask_1((const uint8_t *) &key->ethernet__dstAddr, (const uint8_t *) &_ethernet_->ethernet__dstAddr, \
                     (const uint8_t *) &mask->ethernet__dstAddr, \
                     (uint8_t *) &ethernet__dstAddr, sizeof(struct ethernet__dstAddr_t)); \
        struct ethernet__srcAddr_t ethernet__srcAddr; \
        apply_mask_1((const uint8_t *) &key->ethernet__srcAddr, (const uint8_t *) &_ethernet_->ethernet__srcAddr, \
                     (const uint8_t *) &mask->ethernet__srcAddr, \
                     (uint8_t *) &ethernet__srcAddr, sizeof(struct ethernet__srcAddr_t)); \
        ovs_be16 ethernet__etherType = key->ethernet__etherType | (_ethernet_->ethernet__etherType & ~mask->ethernet__etherType); \
        \
        packet_set__ethernet_( \
            ethernet__dstAddr, \
            ethernet__srcAddr, \
            ethernet__etherType, \
            packet); \
    } \
    \
    static void \
    odp_set_valid(struct dp_packet *packet, const struct ovs_key_valid *key, \
                   const struct ovs_key_valid *mask) \
    { \
        uint8_t _ethernet__valid = key->_ethernet__valid | (packet->_ethernet__valid & ~mask->_ethernet__valid); \
        \
        packet_set_valid( \
            _ethernet__valid, \
            packet); \
    } \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_SET_ACTION_CASES \
    case OVS_KEY_ATTR__ETHERNET_: \
    { \
        const struct ovs_key__ethernet_ *_ethernet__key = \
            nl_attr_get_unspec(a, sizeof(struct ovs_key__ethernet_)); \
        packet_set__ethernet_( \
            _ethernet__key->ethernet__dstAddr, \
            _ethernet__key->ethernet__srcAddr, \
            _ethernet__key->ethernet__etherType, \
            packet); \
        break; \
    } \
    case OVS_KEY_ATTR_VALID: \
    { \
        const struct ovs_key_valid *valid_key = \
            nl_attr_get_unspec(a, sizeof(struct ovs_key_valid)); \
        packet_set_valid( \
            valid_key->_ethernet__valid, \
            packet); \
        break; \
    } \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_MASKED_SET_ACTION_CASES \
    case OVS_KEY_ATTR__ETHERNET_: \
        odp_set__ethernet_(packet, nl_attr_get(a), \
                get_mask(a, struct ovs_key__ethernet_)); \
        break; \
    case OVS_KEY_ATTR_VALID: \
        odp_set_valid(packet, nl_attr_get(a), \
                       get_mask(a, struct ovs_key_valid)); \
        break; \
    \

#endif	/* OVS_MATCH_ODP_EXECUTE_H */
