/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g5a_actor_cleanup_800fff24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._12G5aActorNode = 0x8020803c;
_._14G5aActorMember = 0x8015f558;
base_801628ec = 0x801628ec;
clear_80102474 = 0x80102474;
copy_802eee50 = 0x802eee50;
finish_8020c5c4 = 0x8020c5c4;
free_802134fc = 0x802134fc;
pool_80209920 = 0x80209920;
scalar_801fe1f8 = 0x801fe1f8;
string_80341588 = 0x80341588;
vtable_804105f8 = 0x804105f8;
SECTIONS {
  .text.g5a_actor_cleanup_800fff24 0x800fff24 : { *(.text.g5a_actor_cleanup_800fff24) }
  .sdata 0x804af15c (NOLOAD) : {
    . = 0x0; pool_804af15c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
