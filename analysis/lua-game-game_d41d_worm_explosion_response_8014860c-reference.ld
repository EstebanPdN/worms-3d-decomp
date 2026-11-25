/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41d_worm_explosion_response_8014860c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center2_80066894 = 0x80066894;
center_800668b8 = 0x800668b8;
damage_800668f4 = 0x800668f4;
damage_80148a40 = 0x80148a40;
hit_8043ae20 = 0x8043ae20;
impulse_80148c14 = 0x80148c14;
power_800668fc = 0x800668fc;
query_800fc6dc = 0x800fc6dc;
radius2_800668e4 = 0x800668e4;
radius_800668dc = 0x800668dc;
rand_80162bc8 = 0x80162bc8;
sqrtf_802e82c0 = 0x802e82c0;
sweep_800b0824 = 0x800b0824;
water_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_d41d_worm_explosion_response_8014860c 0x8014860c : { *(.text.w3d_d41d_worm_explosion_response_8014860c) }
  .rodata 0x803a1288 : { *(.rodata) }
  .bss 0x804538c8 : { *(.bss) }
  .sbss 0x804afa70 : { *(.sbss) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; hits_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
