
uint8_t main[] = {
    0x53, 0x50, 0x52, 0x49, 0x54, 0x45, 0x50, 0x4b, // type: spritepk (packed, paletted sprite)
    0x8c, 0x0a, // payload size (2700)

    0x40, 0x00, // width (64)
    0x40, 0x00, // height (64)
    0x08, 0x00, // cols (8)
    0x08, 0x00, // rows (8)

    0x02, // format (paletted)

    0x1e, // number of palette colours (30)
//  r     g     b     a
    0x48, 0x40, 0x37, 0xff,
    0x3d, 0x34, 0x24, 0xff,
    0x52, 0x4a, 0x41, 0xff,
    0x4c, 0x44, 0x33, 0xff,
    0x42, 0x3a, 0x29, 0xff,
    0x41, 0x39, 0x29, 0xff,
    0x42, 0x32, 0x2a, 0xff,
    0x49, 0x39, 0x28, 0xff,
    0x45, 0x35, 0x2c, 0xff,
    0x4d, 0x3d, 0x24, 0xff,
    0x46, 0x36, 0x2e, 0xff,
    0x50, 0x40, 0x2f, 0xff,
    0x35, 0x2c, 0x24, 0xff,
    0x4a, 0x3a, 0x29, 0xff,
    0x3e, 0x2e, 0x1d, 0xff,
    0x33, 0x2b, 0x23, 0xff,
    0x34, 0x24, 0x13, 0xff,
    0x2f, 0x27, 0x1f, 0xff,
    0x3d, 0x24, 0x13, 0xff,
    0x47, 0x2e, 0x1d, 0xff,
    0x29, 0x21, 0x19, 0xff,
    0x50, 0x40, 0x27, 0xff,
    0x2b, 0x23, 0x1a, 0xff,
    0x54, 0x44, 0x2b, 0xff,
    0x56, 0x45, 0x2c, 0xff,
    0x55, 0x45, 0x2c, 0xff,
    0x41, 0x31, 0x28, 0xff,
    0x44, 0x33, 0x2b, 0xff,
    0x4a, 0x31, 0x18, 0xff,
    0x44, 0x2b, 0x12, 0xff,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18,
    0xc6, 0x31, 0x8c, 0x63, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x08, 0x42, 0x13, 0x18, 0xc6, 0x08, 0x42, 0x13, 0x18, 0xc6, 0x31, 0x8c,
    0x60, 0x84, 0x21, 0x31, 0x8c, 0x60, 0x84, 0x21, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52,
    0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x08, 0x42, 0x13, 0x18,
    0xc6, 0x08, 0x42, 0x13, 0x18, 0xc6, 0x31, 0x8c, 0x60, 0x84, 0x21, 0x31, 0x8c, 0x60, 0x84, 0x21,
    0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39,
    0xce, 0x73, 0x9c, 0xe7, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10,
    0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x42, 0x10, 0x84, 0x21,
    0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0x52, 0x94, 0xa5, 0x29, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a,
    0xd6, 0xb5, 0xad, 0x6b, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18,
    0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6,
    0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0x39, 0xce, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde,
    0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08,
    0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x8c, 0x63, 0x18, 0xc6,
    0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63,
    0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0xa5, 0x29, 0x4a, 0x52,
    0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad,
    0x6b, 0x5a, 0xd6, 0xb5, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad,
    0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b,
    0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xb5, 0xad, 0x6b, 0x5a,
    0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6,
    0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6,
    0x31, 0x8c, 0x63, 0x18, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5,
    0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xd6, 0xb5, 0xad, 0x6b,
    0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7,
    0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xde, 0xf7, 0xbd, 0xef,
    0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10,
    0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0x42, 0x10, 0x84, 0x21,
    0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08,
    0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd,
    0xef, 0x7b, 0xde, 0xf7, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a,
    0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7,
    0x39, 0xce, 0x73, 0x9c, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde,
    0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef,
    0x7b, 0xde, 0xf7, 0xbd, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad,
    0x6b, 0x5a, 0xd6, 0xb5, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b,
    0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10,
    0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0x42, 0x10, 0x84, 0x21,
    0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7,
    0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xde, 0xf7, 0xbd, 0xef,
    0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5,
    0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xd6, 0xb5, 0xad, 0x6b,
    0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a,
    0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xe7, 0x39, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6,
    0x31, 0x8c, 0x63, 0x18, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd,
    0xef, 0x7b, 0xde, 0xf7, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad,
    0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a,
    0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xb5, 0xad, 0x6b, 0x5a,
    0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6,
    0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c,
    0xe7, 0x39, 0xce, 0x73, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x8c, 0x63, 0x18, 0xc6,
    0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63,
    0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7,
    0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x7b, 0xde, 0xf7, 0xbd,
    0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7, 0xbd, 0xef,
    0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b,
    0x5a, 0xd6, 0xb5, 0xad, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18,
    0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5,
    0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x5a, 0xd6, 0xb5, 0xad, 0x6b, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0x52, 0x94, 0xa5, 0x29, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a,
    0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39,
    0xce, 0x73, 0x9c, 0xe7, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10,
    0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x42, 0x10, 0x84, 0x21,
    0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08,
    0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29,
    0x4a, 0x52, 0x94, 0xa5, 0x08, 0x42, 0x13, 0x18, 0xc6, 0x08, 0x42, 0x13, 0x18, 0xc6, 0x31, 0x8c,
    0x60, 0x84, 0x21, 0x31, 0x8c, 0x60, 0x84, 0x21, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52,
    0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x08, 0x42, 0x13, 0x18,
    0xc6, 0x08, 0x42, 0x13, 0x18, 0xc6, 0x31, 0x8c, 0x60, 0x84, 0x21, 0x31, 0x8c, 0x60, 0x84, 0x21,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0x08, 0x42, 0x10, 0x84, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10,
    0x84, 0x21, 0x08, 0x42, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42,
    0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x42, 0x10, 0x84,
    0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21
};
