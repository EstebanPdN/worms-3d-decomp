/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002df38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002E59C = 0x8002e59c;
fn_8002E670 = 0x8002e670;
fn_800306A4 = 0x800306a4;
fn_80036540 = 0x80036540;
fn_8003D0A0 = 0x8003d0a0;
fn_8003E314 = 0x8003e314;
fn_8003E370 = 0x8003e370;
fn_80044954 = 0x80044954;
fn_80045FA4 = 0x80045fa4;
fn_800490BC = 0x800490bc;
fn_800FC6DC = 0x800fc6dc;
fn_801248CC = 0x801248cc;
fn_801262E4 = 0x801262e4;
fn_8012632C = 0x8012632c;
fn_8015F5A0 = 0x8015f5a0;
fn_8015FD1C = 0x8015fd1c;
fn_80162024 = 0x80162024;
fn_80165254 = 0x80165254;
fn_80178DF0 = 0x80178df0;
fn_80181CCC = 0x80181ccc;
SECTIONS {
  .text.w3d_auto_8002df38 0x8002df38 : { *(.text.w3d_auto_8002df38) }
  .text.w3d_auto_8002fc88 0x8002fc88 : { *(.text.w3d_auto_8002fc88) }
  .text.w3d_auto_800359e4 0x800359e4 : { *(.text.w3d_auto_800359e4) }
  .text.w3d_auto_80036abc 0x80036abc : { *(.text.w3d_auto_80036abc) }
  .text.w3d_auto_80036afc 0x80036afc : { *(.text.w3d_auto_80036afc) }
  .text.w3d_auto_80036c8c 0x80036c8c : { *(.text.w3d_auto_80036c8c) }
  .text.w3d_auto_80038240 0x80038240 : { *(.text.w3d_auto_80038240) }
  .text.w3d_auto_8003888c 0x8003888c : { *(.text.w3d_auto_8003888c) }
  .text.w3d_auto_80038d1c 0x80038d1c : { *(.text.w3d_auto_80038d1c) }
  .text.w3d_auto_8003cdcc 0x8003cdcc : { *(.text.w3d_auto_8003cdcc) }
  .text.w3d_auto_8003dff8 0x8003dff8 : { *(.text.w3d_auto_8003dff8) }
  .text.w3d_auto_8003e2bc 0x8003e2bc : { *(.text.w3d_auto_8003e2bc) }
  .text.w3d_auto_8003e2e0 0x8003e2e0 : { *(.text.w3d_auto_8003e2e0) }
  .text.w3d_auto_8003ffac 0x8003ffac : { *(.text.w3d_auto_8003ffac) }
  .text.w3d_auto_800441c0 0x800441c0 : { *(.text.w3d_auto_800441c0) }
  .text.w3d_auto_80046228 0x80046228 : { *(.text.w3d_auto_80046228) }
  .text.w3d_auto_80048fac 0x80048fac : { *(.text.w3d_auto_80048fac) }
  .sdata 0x804aa900 (NOLOAD) : {
    . = 0x0; lbl_804AA900 = .;
    . = 0x58; lbl_804AA958 = .;
    . = 0x744; lbl_804AB044 = .;
    . = 0x2750; lbl_804AD050 = .;
    . = 0x2758; lbl_804AD058 = .;
    . = 0x2760; lbl_804AD060 = .;
    . = 0x2768; lbl_804AD068 = .;
    . = 0x2770; lbl_804AD070 = .;
    . = 0x2778; lbl_804AD078 = .;
    . = 0x2780; lbl_804AD080 = .;
    . = 0x2790; lbl_804AD090 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
