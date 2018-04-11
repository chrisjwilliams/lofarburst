/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2018 Oxford Astrophysics
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef LOFARBURST_SOURCE_UDP_UDPSTREAM_H
#define LOFARBURST_SOURCE_UDP_UDPSTREAM_H

#include "lofarburst/source/udp/Config.h"
#include <panda/PacketStream.h>

namespace lofarburst {
namespace source {
namespace udp {

/**
 * @brief
 *     The Udp beamformed data stream
 *
 * @details
 */

template<typename Producer>
class UdpStreamTmpl : public ska::panda::PacketStream<UdpStreamTmpl<Producer>, ska::panda::ConnectionTraits<ska::panda::Udp>, BeamFormerDataTraits, Producer>
{
        typedef ska::panda::ConnectionTraits<ska::panda::Udp> ConnectionTraits;
        typedef ska::panda::PacketStream<UdpStreamTmpl<Producer>, ConnectionTraits, BeamFormerDataTraits, Producer> BaseT;

    public:
        UdpStreamTmpl(Config const& config);
        ~UdpStreamTmpl();

        /**
         * @brief post construction initialisation (called by Producer)
         */
        void init();

        //void deserialise_packet(typename BaseT::ContextPtr& context, typename BeamFormerDataTraits::Packet const& packet);

        // initialise the chunk (size etc.)
        template<typename DataType>
        std::shared_ptr<DataType> get_chunk();

    private:
        unsigned _n_channels;
        unsigned _n_samples;
};

class UdpStream : public UdpStreamTmpl<UdpStream>
{
        typedef UdpStreamTmpl<UdpStream> BaseT;

    public:
        UdpStream(Config const&);
        ~UdpStream();

    private:
};


} // namespace udp
} // namespace source
} // namespace lofarburst
#include "lofarburst/source/udp/detail/UdpStream.cpp"

#endif // LOFARBURST_SOURCE_UDP_UDPSTREAM_H
