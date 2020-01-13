/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/GeneratedFont.hpp>

namespace touchgfx
{
GeneratedFont::GeneratedFont(const GlyphNode* list, uint16_t size, uint16_t height, uint8_t pixBelowBase, uint8_t bitsPerPixel, uint8_t dataFormatA4, uint8_t maxLeft, uint8_t maxRight, const uint8_t* const* glyphDataInternalFlash, const KerningNode* kerningList, const Unicode::UnicodeChar fallbackChar, const Unicode::UnicodeChar ellipsisChar, const uint16_t* const gsubData) :
    ConstFont(list, size, height, pixBelowBase, bitsPerPixel, dataFormatA4, maxLeft, maxRight, fallbackChar, ellipsisChar),
    glyphData(glyphDataInternalFlash),
    kerningData(kerningList),
    gsubTable(gsubData)
{
}

const uint8_t* GeneratedFont::getPixelData(const GlyphNode* glyph) const
{
    const uint8_t* const* table = (const uint8_t* const*)glyphData;
    return &(table[glyph->unicode / 2048][glyph->dataOffset]);
}

int8_t GeneratedFont::getKerning(Unicode::UnicodeChar prevChar, const GlyphNode* glyph) const
{
    if (!glyph || glyph->kerningTableSize == 0)
    {
        return 0;
    }

    uint16_t kerningTablePos = glyph->kerningTablePos();
    for (uint16_t i = kerningTablePos; i < kerningTablePos + glyph->kerningTableSize; i++)
    {
        if (prevChar == kerningData[i].unicodePrevChar)
        {
            return kerningData[i].distance;
        }
    }
    return 0;
}
} // namespace touchgfx