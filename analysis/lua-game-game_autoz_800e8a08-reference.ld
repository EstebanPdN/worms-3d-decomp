/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800e8a08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800E5BB8 = 0x800e5bb8;
fn_800E903C = 0x800e903c;
fn_800FC6DC = 0x800fc6dc;
fn_800FDECC = 0x800fdecc;
fn_801265EC = 0x801265ec;
fn_801797B4 = 0x801797b4;
fn_801A1CF0 = 0x801a1cf0;
fn_801FE1F8 = 0x801fe1f8;
fn_801FE240 = 0x801fe240;
fn_802134FC = 0x802134fc;
fn_8030BE54 = 0x8030be54;
fn_80341584 = 0x80341584;
lbl_8045CCAC = 0x8045ccac;
SECTIONS {
  .text.w3d_auto_800e8a08 0x800e8a08 : { *(.text.w3d_auto_800e8a08) }
  .text.w3d_auto_800f14a8 0x800f14a8 : { *(.text.w3d_auto_800f14a8) }
  .text.w3d_auto_800f895c 0x800f895c : { *(.text.w3d_auto_800f895c) }
  .text.w3d_auto_800fde38 0x800fde38 : { *(.text.w3d_auto_800fde38) }
  .text.w3d_auto_8013bb70 0x8013bb70 : { *(.text.w3d_auto_8013bb70) }
  .text.w3d_auto_8013f08c 0x8013f08c : { *(.text.w3d_auto_8013f08c) }
  .text.w3d_auto_8016aec0 0x8016aec0 : { *(.text.w3d_auto_8016aec0) }
  .text.w3d_auto_801993c8 0x801993c8 : { *(.text.w3d_auto_801993c8) }
  .text.w3d_auto_801a1220 0x801a1220 : { *(.text.w3d_auto_801a1220) }
  .text.w3d_auto_801a18bc 0x801a18bc : { *(.text.w3d_auto_801a18bc) }
  .text.w3d_auto_801e6f0c 0x801e6f0c : { *(.text.w3d_auto_801e6f0c) }
  .text.w3d_auto_801f3fbc 0x801f3fbc : { *(.text.w3d_auto_801f3fbc) }
  .sdata 0x804aaf64 (NOLOAD) : {
    . = 0x0; lbl_804AAF64 = .;
    . = 0x7e0; lbl_804AB744 = .;
    . = 0x7e8; lbl_804AB74C = .;
    . = 0x96c; lbl_804AB8D0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
