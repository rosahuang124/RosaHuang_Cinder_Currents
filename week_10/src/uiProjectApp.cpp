#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "poScene.h"
#include "poNodeContainer.h"
#include "poShape.h"
#include "poImage.h"

#include "CentralCircle.h"
#include "CircleSample.h"



using namespace ci;
using namespace ci::app;
using namespace std;

class uiProjectApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    po::scene::SceneRef mScene;
    po::scene::NodeContainerRef mNodeContainer;
    po::scene::ShapeRef mBackground;
    
    po::scene::SceneRef centralCircleScene;
    po::scene::SceneRef circleScene;
    
//    CentralCircleRef mCentralCircle;
    
    ci::Color mBackgroundColor = ci::Color::hex(0xF4ED98);
 
    po::scene::ShapeRef mCentralCircleBg;
    ci::Color mCentralCircleBgColor = ci::Color::hex(0xFFFFFF);


};

void uiProjectApp::setup()
{
    ci::app::setWindowSize(ci::vec2(375.f, 667.f));
    mNodeContainer = po::scene::NodeContainer::create();
    mScene = po::scene::Scene::create(mNodeContainer);
    
    mBackground = po::scene::Shape::createRect(ci::app::getWindowSize().x, ci::app::getWindowSize().y );
    mBackground->setFillColor(mBackgroundColor);
    mNodeContainer->addChild(mBackground);
    
    centralCircleScene = po::scene::Scene::create(CentralCircle::create());
    circleScene = po::scene::Scene::create(CircleSample::create());
    
    mCentralCircleBg = po::scene::Shape::createCircle(190.f);
    mCentralCircleBg->setFillColor(mCentralCircleBgColor);
    mCentralCircleBg->setPosition( glm::vec2(187.5f, 253.f) );
    mCentralCircleBg->setAlignment(po::scene::Alignment::CENTER_CENTER);
    mNodeContainer->addChild(mCentralCircleBg);


}

void uiProjectApp::mouseDown( MouseEvent event )
{
}

void uiProjectApp::update()
{
    mScene->update();
    circleScene->update();
    centralCircleScene->update();
}

void uiProjectApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mScene->draw();
    centralCircleScene->draw();
    circleScene->draw();
}

CINDER_APP( uiProjectApp, RendererGl( RendererGl::Options().msaa( 8 )) )
