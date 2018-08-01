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

#ifndef OVS_ACTION_ODP_EXECUTE_H
#define	OVS_ACTION_ODP_EXECUTE_H 1

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_FUNCS \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_ACTIONS_CASES \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_REQUIRES_DATAPATH_ASSISTANCE_CASES \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_CALC_FIELDS_SRCS_CASES \
    case OVS_CALC_FIELD_ATTR_ETHERNET__DSTADDR: \
        memcpy(buf, &packet->_ethernet_.ethernet__dstAddr, sizeof packet->_ethernet_.ethernet__dstAddr); \
        buf += sizeof packet->_ethernet_.ethernet__dstAddr; \
        break; \
    case OVS_CALC_FIELD_ATTR_ETHERNET__SRCADDR: \
        memcpy(buf, &packet->_ethernet_.ethernet__srcAddr, sizeof packet->_ethernet_.ethernet__srcAddr); \
        buf += sizeof packet->_ethernet_.ethernet__srcAddr; \
        break; \
    case OVS_CALC_FIELD_ATTR_ETHERNET__ETHERTYPE: \
        memcpy(buf, &packet->_ethernet_.ethernet__etherType, sizeof packet->_ethernet_.ethernet__etherType); \
        buf += sizeof packet->_ethernet_.ethernet__etherType; \
        break; \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_CALC_FIELDS_VERIFY_DST_FIELD_16BIT_CASES \
    case OVS_CALC_FIELD_ATTR_ETHERNET__ETHERTYPE: \
        return (packet->_ethernet_.ethernet__etherType == res16); \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_CALC_FIELDS_UPDATE_DST_FIELD_16BIT_CASES \
    case OVS_CALC_FIELD_ATTR_ETHERNET__ETHERTYPE: \
        packet->_ethernet_.ethernet__etherType = res16; \
        break; \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_ADD_TO_FIELD_CASES \
//    case OVS_KEY_ATTR_ETHERNET__DSTADDR: { \
//        break; \
//    } \
//    case OVS_KEY_ATTR_ETHERNET__SRCADDR: { \
//        break; \
//    } \
//    case OVS_KEY_ATTR_ETHERNET__ETHERTYPE: { \
//        const ovs_be16 *value = nl_attr_get(a); \
//        packet->_ethernet_.ethernet__etherType = htons( \
//                ntohs(packet->_ethernet_.ethernet__etherType) + ntohs(*value)); \
//        break; \
//    } \
//    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_SUB_FROM_FIELD_CASES \
//    case OVS_KEY_ATTR_ETHERNET__DSTADDR: { \
//        break; \
//    } \
//    case OVS_KEY_ATTR_ETHERNET__SRCADDR: { \
//        break; \
//    } \
//    case OVS_KEY_ATTR_ETHERNET__ETHERTYPE: { \
//        const ovs_be16 *value = nl_attr_get(a); \
//        packet->_ethernet_.ethernet__etherType = htons( \
//                ntohs(packet->_ethernet_.ethernet__etherType) - ntohs(*value)); \
//        break; \
//    } \
//    \


/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_ADD_HEADER \
    switch(key) { \
        case OVS_KEY_ATTR__ETHERNET_: \
            packet->_ethernet__valid = 1; \
            break; \
        case __OVS_KEY_ATTR_MAX: \
        default: \
            OVS_NOT_REACHED(); \
    } \
    \

/* -- Called in lib/odp-execute.c -- */
#define OVS_ODP_EXECUTE_REMOVE_HEADER \
    switch(key) { \
        case OVS_KEY_ATTR__ETHERNET_: \
            packet->_ethernet__valid = 0; \
            break; \
        case __OVS_KEY_ATTR_MAX: \
        default: \
            OVS_NOT_REACHED(); \
    } \
    \

#endif	/* OVS_ACTION_ODP_EXECUTE_H */
