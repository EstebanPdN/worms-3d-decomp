/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_actor_restricted_800ef788)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_801797b4 = 0x801797b4;
w3d_empty_80341584 = 0x80341584;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_turns_get_active_actor = 0x80156f88;
SECTIONS {
  .text.k2a_actor_restricted_800ef788 0x800ef788 : { *(.text.k2a_actor_restricted_800ef788) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; w3d_turns_804ab400 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
