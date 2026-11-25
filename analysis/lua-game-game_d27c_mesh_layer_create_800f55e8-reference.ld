/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_mesh_layer_create_800f55e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
heap_802098d8 = 0x802098d8;
memcpy = 0x802eee50;
memmove = 0x802eeef4;
release_802134fc = 0x802134fc;
reset_800f6c64 = 0x800f6c64;
SECTIONS {
  .text.d27c_mesh_layer_create_800f55e8 0x800f55e8 : { *(.text.d27c_mesh_layer_create_800f55e8) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; heap_804adde4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
