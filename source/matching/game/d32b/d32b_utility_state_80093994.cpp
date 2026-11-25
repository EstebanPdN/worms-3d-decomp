/* Girder/utility state constructor (0x80093994): runs the actor base constructor
 * 0x8002a914, installs the table 0x8040f1f8, zeroes the word block +64..+168,
 * default-constructs its four Vec3 arrays (no stores, the empty counted loops of
 * the original) and resets its vectors and scalars. Class and member names are
 * structural; offsets are observed from the original instructions; the unit owns
 * its two float literals at 0x8037ea0c. */
struct D32bActorRoot {
    virtual void slot0();
};
struct D32bActorBase : D32bActorRoot {
    unsigned char unknown[60];
    D32bActorBase();
};
struct D32bVec3 {
    float x, y, z;
    D32bVec3() {}
    void Set(float v) { x = v; y = v; z = v; }
};
struct D32bUtilityState : D32bActorBase {
    int word64, word68, word72, word76, word80, word84, word88, word92, word96, word100, word104, word108, word112, word116, word120, word124, word128, word132, word136, word140, word144, word148, word152, word156, word160, word164;  /* +64..+164 */
    int value168;            /* +168 */
    char unknown172[12];
    D32bVec3 vec184;         /* +184 */
    char unknown196[12];
    D32bVec3 vec208;         /* +208 */
    D32bVec3 vec220;         /* +220 */
    D32bVec3 vec232;         /* +232 */
    char unknown244[36];
    D32bVec3 vec280;         /* +280 */
    int value292, value296, value300;
    float value304;          /* +304 */
    char unknown308[4];
    float value312;          /* +312 */
    char unknown316[8];
    float value324;          /* +324 */
    char unknown328[4];
    float value332;          /* +332 */
    D32bVec3 array8a[8];     /* +336 */
    D32bVec3 array4[4];
    D32bVec3 array8b[8];
    D32bVec3 array8c[8];
    char unknown672[12];
    int value684, value688, value692, value696, value700, value704, value708, value712, value716, value720;
    int value724, value728, value732, value736, value740, value744;
    char unknown748[4];
    int value752;            /* +752 */
    float value756, value760;
    int value764;            /* +764 */
    D32bUtilityState();
    void slot0();
};
D32bUtilityState::D32bUtilityState() : word64(0), word68(0), word72(0), word76(0), word80(0), word84(0), word88(0), word92(0), word96(0), word100(0), word104(0), word108(0), word112(0), word116(0), word120(0), word124(0), word128(0), word132(0), word136(0), word140(0), word144(0), word148(0), word152(0), word156(0), word160(0), word164(0), value168(0)
{
    value724 = 0;
    value728 = 0;
    value732 = 0;
    value736 = 0;
    value752 = 0;
    vec184.Set(0.0f);
    vec208.Set(0.0f);
    value304 = 0.0f;
    value324 = 0.0f;
    value332 = 0.0f;
    value312 = 0.0f;
    value296 = 0;
    value292 = 0;
    value300 = 0;
    value696 = 0;
    value704 = 0;
    value692 = 0;
    value712 = 0;
    value700 = 0;
    value708 = 0;
    value684 = 0;
    value688 = 0;
    value740 = 1;
    value716 = 1;
    value744 = 0;
    vec280.Set(0.0f);
    value756 = 0.0f;
    value764 = 0;
    value760 = 750.0f;
    vec220.Set(0.0f);
    vec232.Set(0.0f);
    value720 = 0;
}
