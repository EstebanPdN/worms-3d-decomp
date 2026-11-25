/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_dtor_80218f1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe1f8 = 0x801fe1f8;
fn_801fe2e0 = 0x801fe2e0;
fn_80210990 = 0x80210990;
fn_802198a0 = 0x802198a0;
fn_802e03e0 = 0x802e03e0;
w3d_vtable_804181c0 = 0x804181c0;
w3d_vtable_80419778 = 0x80419778;
w3d_vtable_80419858 = 0x80419858;
w3d_vtable_8041c9a0 = 0x8041c9a0;
w3d_vtable_8041c9f8 = 0x8041c9f8;
w3d_vtable_8041ca60 = 0x8041ca60;
w3d_vtable_8041cab8 = 0x8041cab8;
SECTIONS {
  .text.w3d_dtor_80218f1c 0x80218f1c : { *(.text.w3d_dtor_80218f1c) }
  .text.w3d_dtor_80219578 0x80219578 : { *(.text.w3d_dtor_80219578) }
  .text.w3d_dtor_802e028c 0x802e028c : { *(.text.w3d_dtor_802e028c) }
  .text.w3d_dtor_802e2ca0 0x802e2ca0 : { *(.text.w3d_dtor_802e2ca0) }
  .sdata 0x804b190c (NOLOAD) : {
    . = 0x0; lbl_804b190c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
