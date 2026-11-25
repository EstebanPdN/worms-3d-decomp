/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a3_crate_append_8005e35c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35a3_action_name_80378edc = 0x80378edc;
sol35a3_allocate_80212fd4 = 0x80212fd4;
sol35a3_copy_802eee50 = 0x802eee50;
sol35a3_name_8015f518 = 0x8015f518;
sol35a3_pool_allocate_802098d8 = 0x802098d8;
sol35a3_release_802134fc = 0x802134fc;
SECTIONS {
  .text.sol35a3_crate_append_8005e35c 0x8005e35c : { *(.text.sol35a3_crate_append_8005e35c) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; sol35a3_pool_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
