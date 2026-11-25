/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ctor_held_801b9910)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801b8928 = 0x801b8928;
fn_801c90c0 = 0x801c90c0;
fn_801c9320 = 0x801c9320;
fn_801ea0ec = 0x801ea0ec;
fn_8023b59c = 0x8023b59c;
fn_8023b738 = 0x8023b738;
w3d_vtable_80414c40 = 0x80414c40;
w3d_vtable_80415618 = 0x80415618;
w3d_vtable_804162d0 = 0x804162d0;
w3d_vtable_80416398 = 0x80416398;
w3d_vtable_8041a0c8 = 0x8041a0c8;
w3d_vtable_8041acc0 = 0x8041acc0;
w3d_vtable_8041ad10 = 0x8041ad10;
w3d_vtable_8041ad88 = 0x8041ad88;
SECTIONS {
  .text.w3d_ctor_held_801b9910 0x801b9910 : { *(.text.w3d_ctor_held_801b9910) }
  .text.w3d_ctor_held_801c3f60 0x801c3f60 : { *(.text.w3d_ctor_held_801c3f60) }
  .text.w3d_ctor_held_801c9320 0x801c9320 : { *(.text.w3d_ctor_held_801c9320) }
  .text.w3d_ctor_held_801ca254 0x801ca254 : { *(.text.w3d_ctor_held_801ca254) }
  .text.w3d_ctor_held_80229c80 0x80229c80 : { *(.text.w3d_ctor_held_80229c80) }
  .text.w3d_ctor_held_8023b738 0x8023b738 : { *(.text.w3d_ctor_held_8023b738) }
  .text.w3d_ctor_held_8023befc 0x8023befc : { *(.text.w3d_ctor_held_8023befc) }
  .text.w3d_ctor_held_8023c470 0x8023c470 : { *(.text.w3d_ctor_held_8023c470) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . = 0x4; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
