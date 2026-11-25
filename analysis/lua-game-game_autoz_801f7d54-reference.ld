/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801f7d54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800F339C = 0x800f339c;
fn_800F6AFC = 0x800f6afc;
fn_8015FD1C = 0x8015fd1c;
fn_801FE1F8 = 0x801fe1f8;
fn_801FE240 = 0x801fe240;
fn_80210990 = 0x80210990;
fn_802134FC = 0x802134fc;
fn_8026ED00 = 0x8026ed00;
fn_802B16C4 = 0x802b16c4;
fn_802B6EFC = 0x802b6efc;
fn_802BAEB8 = 0x802baeb8;
fn_802BCC40 = 0x802bcc40;
fn_802CD0C8 = 0x802cd0c8;
fn_802CD198 = 0x802cd198;
lbl_80418080 = 0x80418080;
lbl_804180A8 = 0x804180a8;
lbl_80473724 = 0x80473724;
SECTIONS {
  .text.w3d_auto_801f7d54 0x801f7d54 : { *(.text.w3d_auto_801f7d54) }
  .text.w3d_auto_80209e64 0x80209e64 : { *(.text.w3d_auto_80209e64) }
  .text.w3d_auto_8026d8a0 0x8026d8a0 : { *(.text.w3d_auto_8026d8a0) }
  .text.w3d_auto_8026fa2c 0x8026fa2c : { *(.text.w3d_auto_8026fa2c) }
  .text.w3d_auto_8026fa7c 0x8026fa7c : { *(.text.w3d_auto_8026fa7c) }
  .text.w3d_auto_802b8754 0x802b8754 : { *(.text.w3d_auto_802b8754) }
  .text.w3d_auto_802bacc8 0x802bacc8 : { *(.text.w3d_auto_802bacc8) }
  .text.w3d_auto_802cd07c 0x802cd07c : { *(.text.w3d_auto_802cd07c) }
  .text.w3d_auto_802cd14c 0x802cd14c : { *(.text.w3d_auto_802cd14c) }
  .text.w3d_auto_8035366c 0x8035366c : { *(.text.w3d_auto_8035366c) }
  .text.w3d_auto_80356e28 0x80356e28 : { *(.text.w3d_auto_80356e28) }
  .text.w3d_auto_80356e90 0x80356e90 : { *(.text.w3d_auto_80356e90) }
  .text.w3d_auto_8035d214 0x8035d214 : { *(.text.w3d_auto_8035d214) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804ABCE4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
