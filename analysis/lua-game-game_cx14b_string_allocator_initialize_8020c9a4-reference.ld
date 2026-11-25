/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14b_string_allocator_initialize_8020c9a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
create_8020baac = 0x8020baac;
default_803426b8 = 0x803426b8;
descriptor_80463348 = 0x80463348;
destroy_8020bab4 = 0x8020bab4;
handle_802097ec = 0x802097ec;
label_803b3170 = 0x803b3170;
label_803b3178 = 0x803b3178;
parent_80463308 = 0x80463308;
register_80200af8 = 0x80200af8;
string_804b06a0 = 0x804b06a0;
SECTIONS {
  .text.w3d_cx14b_string_allocator_initialize_8020c9a4 0x8020c9a4 : { *(.text.w3d_cx14b_string_allocator_initialize_8020c9a4) }
  .sdata 0x804b06a4 (NOLOAD) : {
    . = 0x0; handle_804b06a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
