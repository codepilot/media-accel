void main() {
	gl_Position = ProjectionMatrix * ModelViewMatrix * inVertex;
	outColor = inColor;
	outTexCoord = inTexCoord;
//	outTexCoord = (inVertex + vec4(1, 1, 0 ,0)) * vec4(0.5, 0.5, 1, 1);
}