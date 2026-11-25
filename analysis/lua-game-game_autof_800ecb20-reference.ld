/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800ecb20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002A914 = 0x8002a914;
fn_800ED9C8 = 0x800ed9c8;
fn_800EE720 = 0x800ee720;
fn_800FC43C = 0x800fc43c;
fn_8015F5A0 = 0x8015f5a0;
fn_8015FC58 = 0x8015fc58;
fn_8015FD1C = 0x8015fd1c;
fn_801613F0 = 0x801613f0;
fn_80162024 = 0x80162024;
fn_8016239C = 0x8016239c;
fn_801628B0 = 0x801628b0;
fn_801750F4 = 0x801750f4;
fn_801797B4 = 0x801797b4;
fn_80341584 = 0x80341584;
lbl_8038BD60 = 0x8038bd60;
lbl_8040DB38 = 0x8040db38;
lbl_804102A8 = 0x804102a8;
lbl_80410428 = 0x80410428;
SECTIONS {
  .text.w3d_auto_800ecb20 0x800ecb20 : { *(.text.w3d_auto_800ecb20) }
  .text.w3d_auto_800ee638 0x800ee638 : { *(.text.w3d_auto_800ee638) }
  .text.w3d_auto_800ef614 0x800ef614 : { *(.text.w3d_auto_800ef614) }
  .text.w3d_auto_800efb70 0x800efb70 : { *(.text.w3d_auto_800efb70) }
  .text.w3d_auto_800f6a58 0x800f6a58 : { *(.text.w3d_auto_800f6a58) }
  .text.w3d_auto_800f6fe4 0x800f6fe4 : { *(.text.w3d_auto_800f6fe4) }
  .sdata 0x804aaf04 (NOLOAD) : {
    . = 0x0; lbl_804AAF04 = .;
    . = 0x4004; lbl_804AEF08 = .;
    . = 0x4058; lbl_804AEF5C = .;
    . = 0x4060; lbl_804AEF64 = .;
    . = 0x4068; lbl_804AEF6C = .;
    . = 0x4078; lbl_804AEF7C = .;
    . = 0x40a8; lbl_804AEFAC = .;
    . = 0x40f0; lbl_804AEFF4 = .;
    . = 0x6850; lbl_804B1754 = .;
    . = 0x695c; lbl_804B1860 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
