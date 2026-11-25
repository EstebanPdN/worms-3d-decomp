/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_release_held_800e41d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b0824 = 0x800b0824;
fn_800df684 = 0x800df684;
fn_800e61b8 = 0x800e61b8;
fn_800fddd8 = 0x800fddd8;
fn_800fdf5c = 0x800fdf5c;
SECTIONS {
  .text.w3d_s20_release_held_800e41d8 0x800e41d8 : { *(.text.w3d_s20_release_held_800e41d8) }
  .text.w3d_s20_forward_global4_800e5d4c 0x800e5d4c : { *(.text.w3d_s20_forward_global4_800e5d4c) }
  .text.w3d_s20_check_limit_800e6ec8 0x800e6ec8 : { *(.text.w3d_s20_check_limit_800e6ec8) }
  .text.w3d_s20_forward_global4_800fdd80 0x800fdd80 : { *(.text.w3d_s20_forward_global4_800fdd80) }
  .text.w3d_s20_clear_top_flags_800fdecc 0x800fdecc : { *(.text.w3d_s20_clear_top_flags_800fdecc) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; lbl_804aaecc = .;
    . = 0x98; lbl_804aaf64 = .;
    . = 0x6898; lbl_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
