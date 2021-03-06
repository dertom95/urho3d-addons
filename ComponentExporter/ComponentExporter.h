#pragma once

#include <Urho3D/Core/Object.h>
#include <Urho3D/Math/StringHash.h>
#include <Urho3D/Container/Str.h>
#include <Urho3D/Container/HashSet.h>
#include <Urho3D/Resource/JSONValue.h>

//#define BTH_DEBUG

namespace Urho3D {
    class Context;
    class ResourceCache;
}

using namespace Urho3D;

struct TextureExportPath{
    String resFilepath;
    String absFilepath;


    bool operator==(const TextureExportPath other) const{
        return absFilepath==other.absFilepath;
    }

    bool operator!=(const TextureExportPath other) const{
        return absFilepath!=other.absFilepath;
    }

};


class Urho3DNodeTreeExporter : public Object {
    URHO3D_OBJECT(Urho3DNodeTreeExporter, Object);
public:
    enum ExportMode { WhiteList, BlackList };

    Urho3DNodeTreeExporter(Context* context,ExportMode mode=BlackList);

    void AddComponentHashToFilterList(const StringHash& componentHash);
    // add/discard components that have this component as superclass
    void AddSuperComponentHashToFilterList(const StringHash& componentHash);

    void AddMaterialFolder(const String& folder);
    void AddTechniqueFolder(const String& folder);
    void AddRenderPathFolder(const String& folder);
    void AddTextureFolder(const String& folder);
    void AddAnimationFolder(const String& folder);
    void AddModelFolder(const String& folder);
    void AddParticleFolder(const String& folder);
    void AddSoundFolder(const String& folder);
    void AddSceneFolder(const String& folder);
    void AddObjectFolder(const String& folder);
    void AddFontFolder(const String& folder);
    void AddPostProcessFolder(const String& folder);

    inline void SetResourceCache(SharedPtr<ResourceCache> resCache) { m_resourceCache = resCache; }
    void Export(String filename,bool exportComponentTree=true,bool exportMaterialTree=true);
    void ClearFilters();

    JSONObject ExportComponents();
    JSONObject ExportMaterials();
    JSONObject ExportGlobalData();

    inline void SetExportMode(ExportMode mode){ m_exportMode = mode; }
    inline bool InBlacklistMode() { return m_exportMode == BlackList; }
    inline bool InWhiteListMode() { return m_exportMode == WhiteList; }

    void AddCustomUIFile(const String& filename);


    // don't change the NT_ positions at least not Vectors and colors
    enum NodeType {NT_BOOL=0,NT_FLOAT=1,NT_INT=2,NT_STRING=3,NT_VECTOR2=4,NT_VECTOR3=5,NT_VECTOR4=6,NT_COLOR=7,NT_INTVECTOR2=8,NT_INTVECTOR3=9};
    enum NodeSubType {ST_NONE,ST_PIXEL,ST_UNSIGNED,ST_FACTOR,ST_ANGLE,ST_TIME,ST_DISTANCE};
    enum NodeSocketType {SOCK_FLOAT,SOCK_BOOL,SOCK_STRING,SOCK_VECTOR};

    void NodeSetData(JSONObject& node,const String& id,const String& name,const String category="misc");
    void NodeAddProp(JSONObject& node, const String& name, NodeType type, const String& defaultValue, NodeSubType subType=ST_NONE, int precission=3, float min=0.0f, float max=0.0f);
    void NodeAddPropEnum(JSONObject& node,const String& name,JSONArray& elements, bool categorized=false,const String& defaultValue="0",bool isPreview=false);
    void NodeAddEnumElement(JSONArray& elementsArray, const String& id,const String& name="",const String& descr="",const String& icon="COLOR",const String& number="0",const String& category="");
    void NodeAddInputSocket(JSONObject& node,const String& name, NodeSocketType type);
    void NodeAddOutputSocket(JSONObject& node,const String& name, NodeSocketType type);
private:
    void NodeAddSocket(JSONObject& node,const String& name, NodeSocketType type, bool isInputSocket);

    void ProcessFileSystem();

    bool CheckSuperTypes(const TypeInfo* type);
    String GetTypeCategory(const StringHash& hash,const String& defaultValue);


    JSONObject fileRoot;
    JSONArray trees;

    ExportMode m_exportMode;
    HashSet<StringHash> m_listOfComponents;
    HashSet<StringHash> m_listOfSuperClasses;
    Vector<String> m_materialFolders;
    Vector<String> m_techniqueFolders;
    Vector<String> m_renderPathFolders;
    Vector<String> m_textureFolders;
    Vector<String> m_modelFolders;
    Vector<String> m_animationFolders;
    Vector<String> m_particleFolders;
    Vector<String> m_soundFolders;
    Vector<String> m_sceneFolders;
    Vector<String> m_objectFolders;
    Vector<String> m_fontFolders;
    Vector<String> m_postProcessFolders;

    Vector<String> m_customUIFilenames;

    Vector<String> materialFiles;
    Vector<String> techniqueFiles;
    Vector<String> renderPathFiles;
    Vector<TextureExportPath> textureFiles;
    Vector<TextureExportPath> cubeTextureFiles;
    Vector<String> modelFiles;
    Vector<String> animationFiles;
    Vector<String> particleFiles;
    Vector<String> fontFiles;
    Vector<String> soundFiles;
    Vector<String> objectFiles;
    Vector<String> sceneFiles;
    Vector<String> postprocessFiles;

    SharedPtr<ResourceCache> m_resourceCache;
};
