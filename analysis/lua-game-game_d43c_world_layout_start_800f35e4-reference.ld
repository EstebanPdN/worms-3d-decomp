/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d43c_world_layout_start_800f35e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
create_800f55e8 = 0x800f55e8;
forward_8020b680 = 0x8020b680;
memcpy_802eee50 = 0x802eee50;
place_800f5f44 = 0x800f5f44;
random_800f2cec = 0x800f2cec;
release_802134fc = 0x802134fc;
setup_800f34f8 = 0x800f34f8;
table_8038c640 = 0x8038c640;
type_8041b5c8 = 0x8041b5c8;
SECTIONS {
  .text.d43c_world_layout_start_800f35e4 0x800f35e4 : { *(.text.d43c_world_layout_start_800f35e4) }
  .rodata 0x8038c4d8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
