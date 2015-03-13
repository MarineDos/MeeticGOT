
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <cstdlib>
#include "PartyKel/renderer/Renderer2D.hpp"
#include "PartyKel/renderer/GLtools.hpp"
#include "PartyKel/glm.hpp"


namespace PartyKel {

const GLchar* Renderer2D::VERTEX_SHADER =
"#version 330 core\n"
GL_STRINGIFY(
    layout(location = 0) in vec2 aVertexPosition;

    uniform vec2 uParticlePosition;
    uniform float uParticleScale;

    out vec2 vFragPosition;

    void main() {
        vFragPosition = aVertexPosition;
        gl_Position = vec4(uParticlePosition + uParticleScale * aVertexPosition, 0.f, 1.f);
    }
);

const GLchar* Renderer2D::FRAGMENT_SHADER =
"#version 330 core\n"
GL_STRINGIFY(
    in vec2 vFragPosition;

    out vec4 fFragColor;

    uniform vec3 uParticleColor;

    float computeAttenuation(float distance) {
        return 3.f * exp(-distance * distance * 9.f);
    }

    void main() {
        float distance = length(vFragPosition);
        float attenuation = computeAttenuation(distance);
        fFragColor = vec4(uParticleColor, attenuation);
    }
);

const GLchar* Renderer2D::POLYGON_VERTEX_SHADER =
"#version 330 core\n"
GL_STRINGIFY(
    layout(location = 0) in vec2 aVertexPosition;

    void main() {
        gl_Position = vec4(aVertexPosition, 0.f, 1.f);
    }
);

const GLchar* Renderer2D::POLYGON_FRAGMENT_SHADER =
"#version 330 core\n"
GL_STRINGIFY(
    out vec3 fFragColor;

    uniform vec3 uPolygonColor;

    void main() {
        fFragColor = uPolygonColor;
    }
);

const GLchar* Renderer2D::LINE_VERTEX_SHADER =
"#version 330 core\n"
GL_STRINGIFY(
    layout(location = 0) in vec2 aVertexPosition;
    layout(location = 1) in vec3 aVertexColor;

    out vec3 vFragColor;

    void main() {
        vFragColor = aVertexColor;
        gl_Position = vec4(aVertexPosition, 0.f, 1.f);
    }
);

const GLchar* Renderer2D::LINE_FRAGMENT_SHADER =
"#version 330 core\n"
GL_STRINGIFY(
    out vec3 fFragColor;

    in vec3 vFragColor;

    void main() {
        fFragColor = vFragColor;
    }
);

const GLchar* Renderer2D::TEXTURE_VERTEX_SHADER =
"#version 410 core\n"
GL_STRINGIFY(
layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexTexCoord;

uniform vec2 uParticlePosition;
uniform float uParticleScale;
uniform int uParticleSex;

out block
{
	vec2 TexCoord;
	vec2 vFragPosition;
} Out;

void main() {
	Out.vFragPosition = aVertexPosition;
	Out.TexCoord = aVertexTexCoord;
	if (uParticleSex < 1)
	{
		gl_Position = vec4((uParticlePosition.x + uParticleScale * aVertexPosition.x) - uParticleScale, (uParticlePosition.y + uParticleScale * aVertexPosition.y) - (1.2*uParticleScale), 0.f, 1.f);; 
	}
	else
	{
		gl_Position = vec4((uParticlePosition.x + uParticleScale * aVertexPosition.x) - uParticleScale, (uParticlePosition.y + uParticleScale * aVertexPosition.y) + uParticleScale, 0.f, 1.f);; 
	}
	
}
);

const GLchar* Renderer2D::TEXTURE_FRAGMENT_SHADER =
"#version 410 core\n"
GL_STRINGIFY(

in block
{
	vec2 TexCoord;
	vec2 vFragPosition;
} In;

out vec4 fFragColor;

uniform vec3 uParticleColor;
uniform sampler2D uDiffuse;
uniform float uParticleScale;

void main() {
	
	vec4 diffuse = texture(uDiffuse, In.TexCoord).rgba;
	fFragColor = vec4(diffuse);
}
);

Renderer2D::Renderer2D()
	: m_ProgramID(buildProgram(VERTEX_SHADER, FRAGMENT_SHADER))
	, m_PolygonProgramID(buildProgram(POLYGON_VERTEX_SHADER, POLYGON_FRAGMENT_SHADER))
	, m_LineProgramID(buildProgram(LINE_VERTEX_SHADER, LINE_FRAGMENT_SHADER))
	, m_TextureProgramID(buildProgram(TEXTURE_VERTEX_SHADER, TEXTURE_FRAGMENT_SHADER)) 
{
    // Récuperation des uniforms
    m_uParticleColor = glGetUniformLocation(m_ProgramID, "uParticleColor");
    m_uParticlePosition = glGetUniformLocation(m_ProgramID, "uParticlePosition");
    m_uParticleScale = glGetUniformLocation(m_ProgramID, "uParticleScale");

    m_uPolygonColor = glGetUniformLocation(m_PolygonProgramID, "uPolygonColor");

	m_uDiffuseLocation = glGetUniformLocation(m_TextureProgramID, "uDiffuse");
	m_uParticlePositionLocation = glGetUniformLocation(m_TextureProgramID, "uParticlePosition");
	m_uParticleScaleLocation = glGetUniformLocation(m_TextureProgramID, "uParticleScale");
	m_uParticleSexLocation = glGetUniformLocation(m_TextureProgramID, "uParticleSex");

    // Création du VBO
    glGenBuffers(1, &m_VBOID);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);

    // Une particule est un carré
    GLfloat positions[] = {
        -1.f, -1.f,
         1.f, -1.f,
         1.f,  1.f,
        -1.f,  1.f
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    // Création du VAO
    glGenVertexArrays(1, &m_VAOID);
    glBindVertexArray(m_VAOID);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glGenBuffers(1, &m_PolygonVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, m_PolygonVBOID);
    glGenVertexArrays(1, &m_PolygonVAOID);
    glBindVertexArray(m_PolygonVAOID);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glGenBuffers(1, &m_LinePositionVBOID);
    glGenBuffers(1, &m_LineColorVBOID);
    glGenBuffers(1, &m_LineIBOID);

    glGenVertexArrays(1, &m_LineVAOID);
    glBindVertexArray(m_LineVAOID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_LinePositionVBOID);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_LineColorVBOID);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// TEXTURE
	float quad_vertices[] = { 0.0, 0.0, 1.8, 0.0, 1.8, 0.6, 0.0, 0.6 };
	float m_pUVS[] = { 0.f, 1.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f };

	// Création des deux buffer objects (VBO)
	glGenBuffers(2, m_TextureVBOID);

	// Création du VAO
	glGenVertexArrays(1, &m_TextureVAOID);
	glBindVertexArray(m_TextureVAOID);

	// Bind du buffer object
	glBindBuffer(GL_ARRAY_BUFFER, m_TextureVBOID[0]);
	// Remplissage des données
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), quad_vertices, GL_STATIC_DRAW);
	// Ajouter une entrée dans le VAO sur le channel 0
	glEnableVertexAttribArray(0);
	// Dire comment utiliser les données du buffer object
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, m_TextureVBOID[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_pUVS), m_pUVS, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT)* 2, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	char* textureName[] = {
		"../img/catelyn.png",
		"../img/sansa.png",
		"../img/arya.png",
		"../img/cersei.png",
		"../img/margeary.png",
		"../img/daenarys.png",
		"../img/brienne.png",
		"../img/eddard.png",
		"../img/robb.png",
		"../img/bran.png",
		"../img/jon.png",
		"../img/robert.png",
		"../img/joffrey.png",
		"../img/tywin.png",
		"../img/jaime.png",
		"../img/tyrion.png",
		"../img/stannis.png",
		"../img/loras.png",
		"../img/gregor.png",
		"../img/theon.png"
	};

	// Load image
	for (int i = 0; i < 20; ++i)
	{
		int x;
		int y;
		int comp;
		unsigned char * diffuse = stbi_load(textureName[i], &x, &y, &comp, 4);

		// Create Texture for the cube
		glGenTextures(1, &m_Textures[i]);
		glBindTexture(GL_TEXTURE_2D, m_Textures[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, diffuse);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
}

Renderer2D::~Renderer2D() {
    glDeleteProgram(m_ProgramID);
	glDeleteProgram(m_PolygonProgramID);
	glDeleteProgram(m_LineProgramID);
	glDeleteProgram(m_TextureProgramID);

    glDeleteBuffers(1, &m_VBOID);
    glDeleteBuffers(1, &m_PolygonVBOID);
    glDeleteVertexArrays(1, &m_VAOID);
    glDeleteVertexArrays(1, &m_PolygonVAOID);
}

void Renderer2D::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer2D::drawParticles(
        uint32_t count,
        const glm::vec2* positionArray,
        const float* heightArray,
        const glm::vec3* colorArray,
		const int* sexArray,
        float massScale) {
    // Active la gestion de la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_DEPTH_TEST);

    glUseProgram(m_ProgramID);

    glBindVertexArray(m_VAOID);

    // Dessine chacune des particules
    for(uint32_t i = 0; i < count; ++i) {
        glUniform3fv(m_uParticleColor, 1, glm::value_ptr(colorArray[i]));
        glUniform2fv(m_uParticlePosition, 1, glm::value_ptr(positionArray[i]));
        glUniform1f(m_uParticleScale, massScale * heightArray[i]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    }

	glBindVertexArray(0);

	glUseProgram(m_TextureProgramID);

	// Dessine leur nom
	for (uint32_t i = 0; i < count; ++i) {
		glUniform1i(m_uDiffuseLocation, 0);
		glUniform1f(m_uParticleScaleLocation, massScale * heightArray[i]);
		glUniform2fv(m_uParticlePositionLocation, 1, glm::value_ptr(positionArray[i]));
		glUniform1i(m_uParticleSexLocation, sexArray[i]);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_Textures[i]);
		glBindVertexArray(m_TextureVAOID);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	}

    glBindVertexArray(0);
}

void Renderer2D::drawPolygon(uint32_t count,
                 const glm::vec2* position,
                 const glm::vec3& color,
                 float lineWidth) {
    glBindBuffer(GL_ARRAY_BUFFER, m_PolygonVBOID);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(position[0]), position, GL_DYNAMIC_DRAW);

    glDisable(GL_DEPTH_TEST);

    glLineWidth(lineWidth);

    glUseProgram(m_PolygonProgramID);

    glBindVertexArray(m_PolygonVAOID);

    glUniform3fv(m_uPolygonColor, 1, glm::value_ptr(color));
    glDrawArrays(GL_LINE_LOOP, 0, count);

    glBindVertexArray(0);
}

void Renderer2D::drawLines(
                           uint32_t lineCount,
                           const std::pair<unsigned int, unsigned int>* lines,
                           uint32_t vertexCount,
                           const glm::vec2* positionArray,
                           const glm::vec3* colorArray,
                           float lineWidth) {
    glBindBuffer(GL_ARRAY_BUFFER, m_LinePositionVBOID);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(positionArray[0]), positionArray, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, m_LineColorVBOID);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(colorArray[0]), colorArray, GL_DYNAMIC_DRAW);

    glDisable(GL_DEPTH_TEST);

    glLineWidth(lineWidth);

    glUseProgram(m_LineProgramID);

    glBindVertexArray(m_LineVAOID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_LineIBOID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, lineCount * sizeof(lines[0]), lines, GL_DYNAMIC_DRAW);

    glDrawElements(GL_LINES, lineCount * 2, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

}
