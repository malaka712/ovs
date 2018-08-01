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
 * File:   openvswitch.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_OPENVSWITCH_H
#define	OVS_MATCH_OPENVSWITCH_H 1

/* -- Called in datapath/linux/compat/include/linux/openvswitch.h -- */
#define OVS_KEY_ATTRS \
    OVS_KEY_ATTR__ETHERNET_, \
    OVS_KEY_ATTR__INTRINSIC_METADATA, \
    OVS_KEY_ATTR_VALID, \
    \

/* -- Called in datapath/linux/compat/include/linux/openvswitch.h -- */
#define OVS_KEY_STRUCTS \
    struct ovs_key__ethernet_ { \
        struct ethernet__dstAddr_t ethernet__dstAddr; \
        struct ethernet__srcAddr_t ethernet__srcAddr; \
        ovs_be16 ethernet__etherType; \
    }; \
    \
    struct ovs_key__intrinsic_metadata { \
        uint8_t intrinsic_metadata_mcast_grp_egress_rid; \
        ovs_be16 intrinsic_metadata_mcast_hash; \
        ovs_be32 intrinsic_metadata_lf_field_list; \
    }; \
    \
    struct ovs_key_valid { \
        uint8_t _ethernet__valid; \
    }; \
    \

#endif	/* OVS_MATCH_OPENVSWITCH_H */