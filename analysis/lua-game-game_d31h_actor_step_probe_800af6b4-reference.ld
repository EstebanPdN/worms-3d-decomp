/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31h_actor_step_probe_800af6b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
fire_800d973c = 0x800d973c;
init_80125fdc = 0x80125fdc;
land_800d8b4c = 0x800d8b4c;
lbl_8043ae20 = 0x8043ae20;
lerp_800afc8c = 0x800afc8c;
message_id_8015f5a0 = 0x8015f5a0;
owner_80341584 = 0x80341584;
params_801797b4 = 0x801797b4;
post_8015fc58 = 0x8015fc58;
query_800afb78 = 0x800afb78;
random_801610a0 = 0x801610a0;
sqrt_802e82c0 = 0x802e82c0;
stop_800d8938 = 0x800d8938;
SECTIONS {
  .text.d31h_actor_step_probe_800af6b4 0x800af6b4 : { *(.text.d31h_actor_step_probe_800af6b4) }
  .rodata 0x803822d0 : { *(.rodata) }
  .sdata 0x804ae424 (NOLOAD) : {
    . = 0x0; lbl_804ae424 = .;
    . = 0x8; lbl_804ae42c = .;
    . = 0x3330; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
