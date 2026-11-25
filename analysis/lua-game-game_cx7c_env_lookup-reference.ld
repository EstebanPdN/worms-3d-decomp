/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7c_env_lookup_802eda34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx7c_env_lock_802f3564 = 0x802f3564;
cx7c_env_unlock_802f3568 = 0x802f3568;
cx7c_strncmp_802efb1c = 0x802efb1c;
SECTIONS {
  .text.w3d_cx7c_env_lookup_802eda34 0x802eda34 : { *(.text.w3d_cx7c_env_lookup_802eda34) }
  .sdata 0x804ac5ac (NOLOAD) : {
    . = 0x0; cx7c_environ_804ac5ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
