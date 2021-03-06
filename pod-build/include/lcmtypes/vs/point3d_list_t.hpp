/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>

#ifndef __vs_point3d_list_t_hpp__
#define __vs_point3d_list_t_hpp__

#include <vector>
#include "lcmtypes/vs/point3d_t.hpp"
#include "lcmtypes/vs/color_t.hpp"
#include "lcmtypes/vs/point3d_t.hpp"

namespace vs
{

class point3d_list_t
{
    public:
        int64_t    id;

        int32_t    collection;

        int64_t    element_id;

        int32_t    npoints;

        std::vector< vs::point3d_t > points;

        int32_t    ncolors;

        std::vector< vs::color_t > colors;

        int32_t    nnormals;

        std::vector< vs::point3d_t > normals;

        int32_t    npointids;

        std::vector< int64_t > pointids;

    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to reqad while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "point3d_list_t"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int point3d_list_t::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int point3d_list_t::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int point3d_list_t::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t point3d_list_t::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* point3d_list_t::getTypeName()
{
    return "point3d_list_t";
}

int point3d_list_t::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->id, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->collection, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->element_id, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->npoints, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    for (int a0 = 0; a0 < this->npoints; a0++) {
        tlen = this->points[a0]._encodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->ncolors, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    for (int a0 = 0; a0 < this->ncolors; a0++) {
        tlen = this->colors[a0]._encodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->nnormals, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    for (int a0 = 0; a0 < this->nnormals; a0++) {
        tlen = this->normals[a0]._encodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->npointids, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    if(this->npointids > 0) {
        tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->pointids[0], this->npointids);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int point3d_list_t::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->id, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->collection, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->element_id, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->npoints, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    this->points.resize(this->npoints);
    for (int a0 = 0; a0 < this->npoints; a0++) {
        tlen = this->points[a0]._decodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->ncolors, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    this->colors.resize(this->ncolors);
    for (int a0 = 0; a0 < this->ncolors; a0++) {
        tlen = this->colors[a0]._decodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->nnormals, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    this->normals.resize(this->nnormals);
    for (int a0 = 0; a0 < this->nnormals; a0++) {
        tlen = this->normals[a0]._decodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->npointids, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    if(this->npointids) {
        this->pointids.resize(this->npointids);
        tlen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->pointids[0], this->npointids);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int point3d_list_t::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int64_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int64_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    for (int a0 = 0; a0 < this->npoints; a0++) {
        enc_size += this->points[a0]._getEncodedSizeNoHash();
    }
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    for (int a0 = 0; a0 < this->ncolors; a0++) {
        enc_size += this->colors[a0]._getEncodedSizeNoHash();
    }
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    for (int a0 = 0; a0 < this->nnormals; a0++) {
        enc_size += this->normals[a0]._getEncodedSizeNoHash();
    }
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int64_t_encoded_array_size(NULL, this->npointids);
    return enc_size;
}

uint64_t point3d_list_t::_computeHash(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for(fp = p; fp != NULL; fp = fp->parent)
        if(fp->v == point3d_list_t::getHash)
            return 0;
    const __lcm_hash_ptr cp = { p, (void*)point3d_list_t::getHash };

    uint64_t hash = 0x2263a93c769566c1LL +
         vs::point3d_t::_computeHash(&cp) +
         vs::color_t::_computeHash(&cp) +
         vs::point3d_t::_computeHash(&cp);

    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
