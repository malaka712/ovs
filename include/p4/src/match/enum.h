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
 * File:   enum.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_ENUM_H
#define	OVS_MATCH_ENUM_H 1

/* -- Included in lib/meta-flow.h -- */

/* @Shahbaz:
 * 1. Make sure to add preceding tabs in the following fields. Otherwise, will result in errors.
 * 2. For now prerequisites are not handled.
 * 3. For now all fields are maskable.
 */

    /* "ethernet__dstAddr".
     *
     * ethernet__dstAddr field.
     *
     * Type: be48.
     * Formatting: hexadecimal.
     * Maskable: bitwise.
     * Prerequisites: none.
     * Access: read/write.
     * NXM: none.
     * OXM: OXM_OF_ETHERNET__DSTADDR(45) since OF1.5 and v2.3.
     */
    MFF_ETHERNET__DSTADDR,

    /* "ethernet__srcAddr".
     *
     * ethernet__srcAddr field.
     *
     * Type: be48.
     * Formatting: hexadecimal.
     * Maskable: bitwise.
     * Prerequisites: none.
     * Access: read/write.
     * NXM: none.
     * OXM: OXM_OF_ETHERNET__SRCADDR(46) since OF1.5 and v2.3.
     */
    MFF_ETHERNET__SRCADDR,

    /* "ethernet__etherType".
     *
     * ethernet__etherType field.
     *
     * Type: be16.
     * Formatting: hexadecimal.
     * Maskable: bitwise.
     * Prerequisites: none.
     * Access: read/write.
     * NXM: none.
     * OXM: OXM_OF_ETHERNET__ETHERTYPE(47) since OF1.5 and v2.3.
     */
    MFF_ETHERNET__ETHERTYPE,

    /* "intrinsic_metadata_mcast_grp_egress_rid".
     *
     * intrinsic_metadata_mcast_grp_egress_rid field.
     *
     * Type: be8.
     * Formatting: hexadecimal.
     * Maskable: bitwise.
     * Prerequisites: none.
     * Access: read/write.
     * NXM: none.
     * OXM: OXM_OF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID(48) since OF1.5 and v2.3.
     */
    MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID,

    /* "intrinsic_metadata_mcast_hash".
     *
     * intrinsic_metadata_mcast_hash field.
     *
     * Type: be16.
     * Formatting: hexadecimal.
     * Maskable: bitwise.
     * Prerequisites: none.
     * Access: read/write.
     * NXM: none.
     * OXM: OXM_OF_INTRINSIC_METADATA_MCAST_HASH(49) since OF1.5 and v2.3.
     */
    MFF_INTRINSIC_METADATA_MCAST_HASH,

    /* "intrinsic_metadata_lf_field_list".
     *
     * intrinsic_metadata_lf_field_list field.
     *
     * Type: be32.
     * Formatting: hexadecimal.
     * Maskable: bitwise.
     * Prerequisites: none.
     * Access: read/write.
     * NXM: none.
     * OXM: OXM_OF_INTRINSIC_METADATA_LF_FIELD_LIST(50) since OF1.5 and v2.3.
     */
    MFF_INTRINSIC_METADATA_LF_FIELD_LIST,

    /* "ethernet__valid".
     *
     * ethernet__valid field.
     *
     * Type: be8.
     * Formatting: hexadecimal.
     * Maskable: bitwise.
     * Prerequisites: none.
     * Access: read/write.
     * NXM: none.
     * OXM: OXM_OF_ETHERNET__VALID(51) since OF1.5 and v2.3.
     */
    MFF_ETHERNET__VALID,


/* Do NOT REMOVE THIS. */
    // MFF_N_IDS

#endif	/* OVS_MATCH_ENUM_H */