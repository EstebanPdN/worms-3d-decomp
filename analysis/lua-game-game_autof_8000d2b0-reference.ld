/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8000d2b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80006360 = 0x80006360;
fn_80007514 = 0x80007514;
fn_800097E4 = 0x800097e4;
fn_8001523C = 0x8001523c;
fn_80015264 = 0x80015264;
lbl_80369DD0 = 0x80369dd0;
lbl_8040D880 = 0x8040d880;
lbl_8041D3A0 = 0x8041d3a0;
SECTIONS {
  .text.w3d_auto_8000d2b0 0x8000d2b0 : { *(.text.w3d_auto_8000d2b0) }
  .text.w3d_auto_80015d18 0x80015d18 : { *(.text.w3d_auto_80015d18) }
  .text.w3d_auto_80017870 0x80017870 : { *(.text.w3d_auto_80017870) }
  .text.w3d_auto_80017a1c 0x80017a1c : { *(.text.w3d_auto_80017a1c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
