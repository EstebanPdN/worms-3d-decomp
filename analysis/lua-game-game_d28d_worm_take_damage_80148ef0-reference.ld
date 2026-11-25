/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_take_damage_80148ef0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._6Handle = 0x80178474;
active_worm_803a0e0c = 0x803a0e0c;
alloc_801613f0 = 0x801613f0;
anim_801797b4 = 0x801797b4;
check_801506f8 = 0x801506f8;
engine_80165254 = 0x80165254;
get_803426b4 = 0x803426b4;
get_80342fa4 = 0x80342fa4;
int_message_800a82f0 = 0x800a82f0;
item_800fc710 = 0x800fc710;
log_80022e20 = 0x80022e20;
logic_entity_803a0e2c = 0x803a0e2c;
msg_id_8015f5a0 = 0x8015f5a0;
pool_add_800c53a0 = 0x800c53a0;
post_8016239c = 0x8016239c;
query_800fc6dc = 0x800fc6dc;
set_state_801492ec = 0x801492ec;
set_vector_80178fa4 = 0x80178fa4;
setting_800fc1f0 = 0x800fc1f0;
target_message_801190b4 = 0x801190b4;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
update_80178c54 = 0x80178c54;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d28d_worm_take_damage_80148ef0 0x80148ef0 : { *(.text.d28d_worm_take_damage_80148ef0) }
  .rodata 0x803a12c8 : { *(.rodata) }
  .sdata 0x804afba0 (NOLOAD) : {
    . = 0x0; cacheC_804afba0 = .;
    . = 0x150; cacheA_804afcf0 = .;
    . = 0x170; cacheB_804afd10 = .;
    . = 0x1d8; cacheD_804afd78 = .;
    . = 0x1bb4; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
