/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_actor_die_or_spawn_800ed13c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
assign_800eb65c = 0x800eb65c;
attach_80164514 = 0x80164514;
copy_800eb8d0 = 0x800eb8d0;
copy_800eb8f0 = 0x800eb8f0;
ctx_80165254 = 0x80165254;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
finish_8015fd1c = 0x8015fd1c;
forward_8020b680 = 0x8020b680;
key_8040f038 = 0x8040f038;
shoot_800ec6a8 = 0x800ec6a8;
type_80368418 = 0x80368418;
SECTIONS {
  .text.d26c_actor_die_or_spawn_800ed13c 0x800ed13c : { *(.text.d26c_actor_die_or_spawn_800ed13c) }
  .rodata 0x8038b5fc : { *(.rodata) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; owner_804aab4c = .;
    . = 0x6c40; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
