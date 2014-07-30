//#define USE_64bit

void main() {
//color = texture(tex, gl_FragCoord.xy / viewport.zw);// + inColor;
	#ifdef USE_64bit
		color = texture(tex, inTexCoord.xy) * (32.12549019607843 / 1.0);// + inColor;
	#else
		color = texture(tex, inTexCoord.xy);// + inColor;
	#endif

//	color.a = 1;
//if(color.a < 0.75) discard;
}