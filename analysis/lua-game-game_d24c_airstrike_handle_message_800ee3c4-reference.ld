/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_airstrike_handle_message_800ee3c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
activate_800eeadc = 0x800eeadc;
arena_801613f0 = 0x801613f0;
base_8015fb34 = 0x8015fb34;
countdown_800eebf8 = 0x800eebf8;
finish_800ee934 = 0x800ee934;
fn_80164514 = 0x80164514;
forward_8020b680 = 0x8020b680;
id_equals_8015f65c = 0x8015f65c;
identity_80341584 = 0x80341584;
init_800ee638 = 0x800ee638;
key_80410318 = 0x80410318;
message_id_8015f5a0 = 0x8015f5a0;
message_vtable_8040db38 = 0x8040db38;
msg_init_801190b4 = 0x801190b4;
post_8016239c = 0x8016239c;
remove_8015fd1c = 0x8015fd1c;
restricted_800ef788 = 0x800ef788;
settings_801797b4 = 0x801797b4;
stop_800ef614 = 0x800ef614;
target_800ef680 = 0x800ef680;
SECTIONS {
  .text.d24c_airstrike_handle_message_800ee3c4 0x800ee3c4 : { *(.text.d24c_airstrike_handle_message_800ee3c4) }
  .sdata 0x804aef5c (NOLOAD) : {
    . = 0x0; e_804aef5c = .;
    . = 0x8; b_804aef64 = .;
    . = 0x10; a_804aef6c = .;
    . = 0x28; m3_804aef84 = .;
    . = 0x38; m2_804aef94 = .;
    . = 0x50; c_804aefac = .;
    . = 0x68; m1_804aefc4 = .;
    . = 0x98; d_804aeff4 = .;
    . = 0x27f8; arena_804b1754 = .;
    . = 0x2830; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
