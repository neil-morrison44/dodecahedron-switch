#ifdef __has_attribute
#define HAVE_ATTRIBUTE(x) __has_attribute(x)
#else
#define HAVE_ATTRIBUTE(x) 0
#endif
#if HAVE_ATTRIBUTE(aligned) || (defined(__GNUC__) && !defined(__clang__))
#define DATA_ALIGN_ATTRIBUTE __attribute__((aligned(4)))
#else
#define DATA_ALIGN_ATTRIBUTE
#endif

const unsigned char model_data[] DATA_ALIGN_ATTRIBUTE = {
    0x28, 0x00, 0x00, 0x00, 0x54, 0x46, 0x4c, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00,
    0x1c, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x14, 0x00,
    0x00, 0x00, 0x18, 0x00, 0x12, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xf0, 0x06, 0x00, 0x00, 0x28, 0x03, 0x00, 0x00, 0x10, 0x03, 0x00, 0x00,
    0x3c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x04, 0x00, 0x08, 0x00,
    0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
    0x13, 0x00, 0x00, 0x00, 0x6d, 0x69, 0x6e, 0x5f, 0x72, 0x75, 0x6e, 0x74,
    0x69, 0x6d, 0x65, 0x5f, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x00,
    0x0a, 0x00, 0x00, 0x00, 0xc0, 0x02, 0x00, 0x00, 0xac, 0x02, 0x00, 0x00,
    0x80, 0x02, 0x00, 0x00, 0x3c, 0x02, 0x00, 0x00, 0x98, 0x01, 0x00, 0x00,
    0x64, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
    0x30, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xd2, 0xfc, 0xff, 0xff,
    0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x31, 0x2e, 0x35, 0x2e,
    0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xd0, 0xf9, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0xf9, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf9, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x22, 0xfd, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00,
    0x20, 0x01, 0x00, 0x00, 0x4f, 0x5b, 0xc8, 0x3e, 0xe7, 0xd7, 0xf2, 0xbe,
    0xce, 0xcf, 0x25, 0xbe, 0x18, 0x95, 0x2e, 0xbf, 0x32, 0x65, 0x84, 0xbe,
    0xdc, 0xd6, 0xba, 0xbe, 0x33, 0xde, 0xd3, 0xba, 0x76, 0x44, 0xb2, 0xbe,
    0x05, 0xa4, 0x10, 0xbf, 0x2e, 0x6c, 0xae, 0x3d, 0xa9, 0xd2, 0xcb, 0x3d,
    0xf0, 0xbb, 0xf3, 0x3e, 0xda, 0x82, 0xec, 0xbe, 0x76, 0xcb, 0xf6, 0xbe,
    0x98, 0xf7, 0xe2, 0xbe, 0x93, 0xf7, 0xb9, 0xbe, 0x78, 0xea, 0x63, 0x3e,
    0xa2, 0xdc, 0x03, 0xbe, 0x18, 0xdc, 0x11, 0xbe, 0xb1, 0xfc, 0x0d, 0xbf,
    0x0d, 0x04, 0x30, 0x3e, 0x88, 0x0f, 0xdc, 0xbd, 0x72, 0x21, 0xb1, 0x3e,
    0x24, 0xdf, 0x4b, 0xbf, 0x92, 0x4e, 0x80, 0x3e, 0x4d, 0xfc, 0x3d, 0xbe,
    0x9c, 0x15, 0xc5, 0x3e, 0x36, 0xab, 0xf2, 0xbc, 0x84, 0x9f, 0x07, 0x3f,
    0x09, 0x4e, 0xd9, 0xbe, 0x1b, 0x47, 0x32, 0x3f, 0xea, 0xeb, 0x05, 0x3e,
    0x7a, 0xde, 0x62, 0xbe, 0x1c, 0x1e, 0x19, 0xbe, 0xbe, 0x77, 0x5c, 0xbc,
    0x3e, 0x47, 0x1e, 0x3e, 0x29, 0x5b, 0x9c, 0x3e, 0x93, 0x40, 0x95, 0x3e,
    0x99, 0xf6, 0x99, 0xbe, 0x4a, 0xf5, 0xf7, 0x3e, 0xd1, 0x1a, 0xf1, 0xbe,
    0x0f, 0x2d, 0x95, 0x3d, 0xd6, 0x63, 0x16, 0xbf, 0x1c, 0x48, 0x42, 0x3e,
    0x4c, 0xc9, 0x9d, 0xbe, 0x8b, 0xf5, 0xf8, 0x3d, 0x13, 0x0e, 0x4b, 0xbe,
    0xb7, 0xfa, 0x9c, 0x3e, 0xd8, 0x62, 0x0e, 0xbf, 0x6d, 0x57, 0x50, 0x3a,
    0x30, 0xbe, 0x95, 0xbe, 0x0c, 0xed, 0xb6, 0xbc, 0x36, 0x26, 0x64, 0x3e,
    0x80, 0x29, 0x1f, 0xbf, 0x5b, 0xb7, 0x5a, 0xbe, 0x89, 0xfa, 0xf9, 0x3e,
    0xda, 0x67, 0xaf, 0x3c, 0x9a, 0xbc, 0x4e, 0xbe, 0xd3, 0x92, 0x1d, 0x3f,
    0x69, 0x51, 0x52, 0xbf, 0x2a, 0x9f, 0x9a, 0x3e, 0x76, 0xd1, 0x77, 0x3e,
    0x58, 0xc2, 0x1b, 0x3f, 0x38, 0x32, 0xd3, 0x3e, 0x0d, 0x37, 0x8a, 0xbe,
    0x59, 0x6c, 0xbd, 0xbe, 0x5a, 0xd5, 0xe3, 0xbe, 0xd2, 0x5b, 0xd9, 0x3e,
    0x70, 0xe2, 0x3b, 0x3d, 0x7a, 0x94, 0x20, 0x3f, 0x41, 0x21, 0x64, 0x3e,
    0xc5, 0x18, 0x05, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x52, 0xfe, 0xff, 0xff,
    0x04, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x96, 0x81, 0x30, 0x3f,
    0xdf, 0xa0, 0x4f, 0x3d, 0x3f, 0x46, 0x84, 0xbf, 0xbc, 0x8f, 0xe6, 0x3d,
    0xb3, 0xe8, 0x02, 0xbf, 0x04, 0xbd, 0x8a, 0x3e, 0x63, 0x35, 0x57, 0xbf,
    0xcc, 0xda, 0xa0, 0xbd, 0xbb, 0x3e, 0xe3, 0xbe, 0x43, 0x99, 0x14, 0x3f,
    0x8e, 0xae, 0x88, 0xbe, 0xc2, 0xb6, 0x0b, 0xbf, 0xe8, 0xce, 0xc2, 0x3d,
    0x04, 0x3c, 0x1d, 0xbf, 0x97, 0x0f, 0xd6, 0xbe, 0xdb, 0x42, 0x45, 0xbe,
    0x73, 0x22, 0xb0, 0x3e, 0xfb, 0x2f, 0xf8, 0xbe, 0xcf, 0x71, 0x2c, 0xbf,
    0xeb, 0x52, 0x30, 0x3e, 0xe5, 0xe7, 0xf0, 0xbd, 0xec, 0xad, 0x95, 0xbe,
    0x99, 0xd9, 0x23, 0xbf, 0x7f, 0xa0, 0x11, 0x3e, 0xb3, 0xb6, 0xc8, 0x3e,
    0x84, 0xde, 0xf4, 0xbe, 0xc0, 0xed, 0x7a, 0xbe, 0xc7, 0x2b, 0x6e, 0x3e,
    0xe8, 0xf6, 0x43, 0x3f, 0x44, 0x8c, 0x7d, 0x3e, 0xfc, 0xae, 0xa2, 0x3e,
    0xcc, 0xa4, 0x3f, 0x3f, 0x5d, 0x79, 0x8a, 0xbe, 0x51, 0x87, 0xa0, 0x3d,
    0x4b, 0x45, 0xa9, 0xbd, 0x0d, 0x36, 0x3b, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0xf2, 0xfe, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
    0xbf, 0x35, 0xba, 0xbd, 0xf4, 0xce, 0xf6, 0x3d, 0x55, 0x0f, 0x8c, 0x3d,
    0x95, 0x80, 0xae, 0x3d, 0xf9, 0x18, 0xdc, 0xbd, 0xc0, 0x5b, 0x81, 0xbe,
    0x4c, 0xe6, 0x1a, 0x3e, 0x1e, 0xab, 0x86, 0xbe, 0xf9, 0x34, 0x6a, 0x3e,
    0x30, 0xe4, 0x9c, 0xbd, 0xd3, 0x52, 0xd3, 0x3e, 0x76, 0xfd, 0xa8, 0xbc,
    0x00, 0x00, 0x00, 0x00, 0x32, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00,
    0x18, 0x00, 0x00, 0x00, 0xec, 0xd6, 0x0e, 0x3e, 0x44, 0x8e, 0x28, 0xbe,
    0x1c, 0x20, 0xbf, 0x3e, 0x21, 0xdb, 0xfb, 0x3c, 0x02, 0x56, 0x92, 0xbc,
    0x33, 0x9f, 0x55, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x30, 0xfc, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0xfc, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0x00, 0x00, 0x00, 0x4d, 0x4c, 0x49, 0x52, 0x20, 0x43, 0x6f, 0x6e,
    0x76, 0x65, 0x72, 0x74, 0x65, 0x64, 0x2e, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x18, 0x00, 0x04, 0x00,
    0x08, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x14, 0x00, 0x0e, 0x00, 0x00, 0x00,
    0xf8, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x94, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0e, 0x00, 0x1a, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00,
    0x07, 0x00, 0x14, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    0x01, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x04, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x01, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
    0xce, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x08, 0x18, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0xfd, 0xff, 0xff,
    0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c, 0x00,
    0x07, 0x00, 0x10, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x18, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x48, 0xfd, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
    0x64, 0x02, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x88, 0x01, 0x00, 0x00,
    0x44, 0x01, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00,
    0x4c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xd0, 0xfd, 0xff, 0xff,
    0x34, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
    0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00, 0xbc, 0xfd, 0xff, 0xff,
    0x08, 0x00, 0x00, 0x00, 0x49, 0x64, 0x65, 0x6e, 0x74, 0x69, 0x74, 0x79,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x14, 0xfe, 0xff, 0xff, 0x44, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
    0x0c, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x1a, 0x00, 0x00, 0x00,
    0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x2f, 0x64,
    0x65, 0x6e, 0x73, 0x65, 0x5f, 0x31, 0x2f, 0x42, 0x69, 0x61, 0x73, 0x41,
    0x64, 0x64, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x68, 0xfe, 0xff, 0xff, 0x44, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
    0x06, 0x00, 0x00, 0x00, 0x54, 0xfe, 0xff, 0xff, 0x18, 0x00, 0x00, 0x00,
    0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x2f, 0x64,
    0x65, 0x6e, 0x73, 0x65, 0x2f, 0x42, 0x69, 0x61, 0x73, 0x41, 0x64, 0x64,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x22, 0xff, 0xff, 0xff, 0x34, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x98, 0xfe, 0xff, 0xff, 0x19, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75,
    0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x2f, 0x64, 0x65, 0x6e, 0x73, 0x65,
    0x5f, 0x31, 0x2f, 0x4d, 0x61, 0x74, 0x4d, 0x75, 0x6c, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x66, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xdc, 0xfe, 0xff, 0xff,
    0x17, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74, 0x69,
    0x61, 0x6c, 0x2f, 0x64, 0x65, 0x6e, 0x73, 0x65, 0x2f, 0x4d, 0x61, 0x74,
    0x4d, 0x75, 0x6c, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00, 0xa6, 0xff, 0xff, 0xff, 0x4c, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x1c, 0xff, 0xff, 0xff, 0x32, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75,
    0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x2f, 0x64, 0x65, 0x6e, 0x73, 0x65,
    0x5f, 0x31, 0x2f, 0x42, 0x69, 0x61, 0x73, 0x41, 0x64, 0x64, 0x2f, 0x52,
    0x65, 0x61, 0x64, 0x56, 0x61, 0x72, 0x69, 0x61, 0x62, 0x6c, 0x65, 0x4f,
    0x70, 0x2f, 0x72, 0x65, 0x73, 0x6f, 0x75, 0x72, 0x63, 0x65, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
    0x14, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00,
    0x0e, 0x00, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x84, 0xff, 0xff, 0xff,
    0x30, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74, 0x69,
    0x61, 0x6c, 0x2f, 0x64, 0x65, 0x6e, 0x73, 0x65, 0x2f, 0x42, 0x69, 0x61,
    0x73, 0x41, 0x64, 0x64, 0x2f, 0x52, 0x65, 0x61, 0x64, 0x56, 0x61, 0x72,
    0x69, 0x61, 0x62, 0x6c, 0x65, 0x4f, 0x70, 0x2f, 0x72, 0x65, 0x73, 0x6f,
    0x75, 0x72, 0x63, 0x65, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x14, 0x00, 0x18, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00,
    0x14, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x06, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x69, 0x6e, 0x70, 0x75, 0x74, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x19, 0x0a, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00,
    0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x03, 0x00, 0x00, 0x00};
const int model_data_len = 1872;
