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
#include "lofarburst/source/udp/test/BeamFormerPacketInspectorTest.h"
#include "lofarburst/source/udp/BeamFormerPacketInspector.h"


namespace lofarburst {
namespace source {
namespace udp {
namespace test {


BeamFormerPacketInspectorTest::BeamFormerPacketInspectorTest()
    : ::testing::Test()
{
}

BeamFormerPacketInspectorTest::~BeamFormerPacketInspectorTest()
{
}

void BeamFormerPacketInspectorTest::SetUp()
{
}

void BeamFormerPacketInspectorTest::TearDown()
{
}

TEST_F(BeamFormerPacketInspectorTest, test_sequence_number)
{
    BeamFormerPacketHeader header;
    header.sequence_number(0);
    BeamFormerPacketInspector::Packet packet;
    packet.set_header(header);
    {
        BeamFormerPacketInspector inspector(packet);
        ASSERT_EQ(0U, inspector.sequence_number());
    }
    header.sequence_number(55);
    packet.set_header(header);
    {
        BeamFormerPacketInspector inspector(packet);
        ASSERT_EQ(55U, inspector.sequence_number());
    }
}

TEST_F(BeamFormerPacketInspectorTest, test_channel)
{
    BeamFormerPacketHeader header;
    header.channel(0);
    BeamFormerPacketInspector::Packet packet;
    packet.set_header(header);
    {
        BeamFormerPacketInspector inspector(packet);
        ASSERT_EQ(0U, inspector.channel());
    }
    header.channel(55);
    packet.set_header(header);
    {
        BeamFormerPacketInspector inspector(packet);
        ASSERT_EQ(55U, inspector.channel());
    }
}

} // namespace test
} // namespace udp
} // namespace source
} // namespace lofarburst
