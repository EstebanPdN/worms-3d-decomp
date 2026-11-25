/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_initialize_mesh_messages_800a1670)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8009FEB8 = 0x8009feb8;
fn_8015F518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_803606C0 = 0x803606c0;
lbl_803617D0 = 0x803617d0;
lbl_80380930 = 0x80380930;
lbl_80380944 = 0x80380944;
lbl_8038095C = 0x8038095c;
lbl_80380974 = 0x80380974;
lbl_8038098C = 0x8038098c;
lbl_803809A0 = 0x803809a0;
lbl_803809BC = 0x803809bc;
lbl_803809D4 = 0x803809d4;
lbl_803809F0 = 0x803809f0;
lbl_803E7DF8 = 0x803e7df8;
lbl_80437D24 = 0x80437d24;
SECTIONS {
  .text.s8_initialize_mesh_messages_800a1670 0x800a1670 : { *(.text.s8_initialize_mesh_messages_800a1670) }
  .rodata 0x80380a0c : { *(.rodata) }
  .sdata 0x804ae12c (NOLOAD) : {
    . = 0x0; lbl_804AE12C = .;
    . = 0x8; lbl_804AE134 = .;
    . = 0x10; lbl_804AE13C = .;
    . = 0x18; lbl_804AE144 = .;
    . = 0x20; lbl_804AE14C = .;
    . = 0x28; lbl_804AE154 = .;
    . = 0x30; lbl_804AE15C = .;
    . = 0x38; lbl_804AE164 = .;
    . = 0x40; lbl_804AE16C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
