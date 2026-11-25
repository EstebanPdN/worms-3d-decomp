/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40h_land_point_test_800b4da0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
grid_test_8002c73c = 0x8002c73c;
lbl_8038252c = 0x8038252c;
lbl_8038258c = 0x8038258c;
lbl_8038264c = 0x8038264c;
SECTIONS {
  .text.d40h_land_point_test_800b4da0 0x800b4da0 : { *(.text.d40h_land_point_test_800b4da0) }
  .rodata 0x80382490 : { *(.rodata) }
  .sdata 0x804ae4b0 (NOLOAD) : {
    . = 0x0; lbl_804ae4b0 = .;
    . = 0x4; lbl_804ae4b4 = .;
    . = 0x8; lbl_804ae4b8 = .;
    . = 0xc; lbl_804ae4bc = .;
    . = 0x10; lbl_804ae4c0 = .;
    . = 0x14; lbl_804ae4c4 = .;
    . = 0x19; lbl_804ae4c9 = .;
    . = 0x1b; lbl_804ae4cb = .;
    . = 0x1c; lbl_804ae4cc = .;
    . = 0x1d; lbl_804ae4cd = .;
    . = 0x1e; lbl_804ae4ce = .;
    . = 0x20; lbl_804ae4d0 = .;
    . = 0x28; lbl_804ae4d8 = .;
    . = 0x2c; lbl_804ae4dc = .;
    . = 0x30; lbl_804ae4e0 = .;
    . = 0x34; lbl_804ae4e4 = .;
    . = 0x38; lbl_804ae4e8 = .;
    . = 0x40; lbl_804ae4f0 = .;
    . = 0x48; lbl_804ae4f8 = .;
    . = 0x4c; lbl_804ae4fc = .;
    . = 0x50; lbl_804ae500 = .;
    . = 0x54; lbl_804ae504 = .;
    . = 0x58; lbl_804ae508 = .;
    . = 0x5c; lbl_804ae50c = .;
    . = 0x3350; lbl_804b1800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
