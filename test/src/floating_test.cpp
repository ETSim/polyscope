// Copyright 2017-2023, Nicholas Sharp and the Polyscope contributors. https://polyscope.run

#include "polyscope_test.h"

#include "polyscope/floating_quantities.h"

// ============================================================
// =============== Floating image
// ============================================================

// Add floating images

TEST_F(PolyscopeTest, FloatingImageTest) {


  size_t dimX = 300;
  size_t dimY = 200;

  { // ScalarImageQuantity
    std::vector<float> vals(dimX * dimY, 0.44);
    polyscope::ScalarImageQuantity* im =
        polyscope::addScalarImageQuantity("im scalar", dimX, dimY, vals, polyscope::ImageOrigin::UpperLeft);
    polyscope::show(3);
    im->setShowFullscreen(true);
    polyscope::show(3);

    // try some options
    im->setIsolinesEnabled(true);
    polyscope::show(3);
    im->setIsolineStyle(polyscope::IsolineStyle::Contour);
    polyscope::show(3);

    // categorical
    polyscope::ScalarImageQuantity* im2 = polyscope::addScalarImageQuantity(
        "im scalar cat", dimX, dimY, vals, polyscope::ImageOrigin::UpperLeft, polyscope::DataType::CATEGORICAL);
    polyscope::show(3);
    im2->setShowFullscreen(true);
    polyscope::show(3);
  }

  { // ColorImageQuantity
    std::vector<std::array<float, 3>> valsRGB(dimX * dimY, std::array<float, 3>{0.44, 0.55, 0.66});
    polyscope::ColorImageQuantity* im =
        polyscope::addColorImageQuantity("im color", dimX, dimY, valsRGB, polyscope::ImageOrigin::UpperLeft);
    polyscope::show(3);
    im->setShowFullscreen(true);
    polyscope::show(3);
  }

  { // ColorImageQuantity lower left
    std::vector<std::array<float, 3>> valsRGB(dimX * dimY, std::array<float, 3>{0.44, 0.55, 0.66});
    polyscope::ColorImageQuantity* im =
        polyscope::addColorImageQuantity("im color lower left", dimX, dimY, valsRGB, polyscope::ImageOrigin::LowerLeft);
    polyscope::show(3);
    im->setShowFullscreen(true);
    polyscope::show(3);
  }

  { // ColorAlphaImageQuantity
    std::vector<std::array<float, 4>> valsRGBA(dimX * dimY, std::array<float, 4>{0.44, 0.55, 0.66, 0.77});
    polyscope::ColorImageQuantity* im = polyscope::addColorAlphaImageQuantity("im color alpha", dimX, dimY, valsRGBA,
                                                                              polyscope::ImageOrigin::UpperLeft);
    polyscope::show(3);
    im->setShowFullscreen(true);
    polyscope::show(3);

    im->setIsPremultiplied(true);
    polyscope::show(3);
  }

  // make sure it doesn't blow up with transparancy
  polyscope::options::transparencyMode = polyscope::TransparencyMode::Simple;
  polyscope::show(3);

  polyscope::options::transparencyMode = polyscope::TransparencyMode::Pretty;
  polyscope::show(3);

  polyscope::options::transparencyMode = polyscope::TransparencyMode::None;

  // make sure removing works
  polyscope::removeFloatingQuantity("im color", true);
  polyscope::show(3);

  polyscope::removeAllStructures();
}

TEST_F(PolyscopeTest, FloatingRenderImageTest) {


  size_t dimX = 300;
  size_t dimY = 200;

  std::vector<float> depthVals(dimX * dimY, 0.44);
  std::vector<std::array<float, 3>> normalVals(dimX * dimY, std::array<float, 3>{0.44, 0.55, 0.66});
  std::vector<std::array<float, 3>> normalValsEmpty;
  std::vector<std::array<float, 3>> colorVals(dimX * dimY, std::array<float, 3>{0.44, 0.55, 0.66});
  std::vector<std::array<float, 4>> colorAlphaVals(dimX * dimY, std::array<float, 4>{0.44, 0.55, 0.66, 0.77});
  std::vector<float> scalarVals(dimX * dimY, 0.44);

  { // DepthRenderImageQuantity
    polyscope::DepthRenderImageQuantity* im = polyscope::addDepthRenderImageQuantity(
        "render im depth", dimX, dimY, depthVals, normalVals, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, normalVals);
    im->setEnabled(true);
    polyscope::show(3);
  }
  { // with no normals
    polyscope::DepthRenderImageQuantity* im = polyscope::addDepthRenderImageQuantity(
        "render im depth no normal", dimX, dimY, depthVals, normalValsEmpty, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, normalValsEmpty);
    im->setEnabled(true);
    polyscope::show(3);
  }

  { // ColorImageQuantity
    polyscope::ColorRenderImageQuantity* im = polyscope::addColorRenderImageQuantity(
        "render im color", dimX, dimY, depthVals, normalVals, colorVals, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, normalVals, colorVals);
    im->setEnabled(true);
    polyscope::show(3);
  }
  { // with no normals
    polyscope::ColorRenderImageQuantity* im = polyscope::addColorRenderImageQuantity(
        "render im color", dimX, dimY, depthVals, normalValsEmpty, colorVals, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, normalValsEmpty, colorVals);
    im->setEnabled(true);
    polyscope::show(3);
  }

  { // ScalarRenderImageQuantity
    polyscope::ScalarRenderImageQuantity* im = polyscope::addScalarRenderImageQuantity(
        "render im scalar", dimX, dimY, depthVals, normalVals, scalarVals, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, normalVals, scalarVals);
    im->setEnabled(true);
    polyscope::show(3);
  }
  { // with no normals
    polyscope::ScalarRenderImageQuantity* im = polyscope::addScalarRenderImageQuantity(
        "render im scalar", dimX, dimY, depthVals, normalValsEmpty, scalarVals, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, normalValsEmpty, scalarVals);
    im->setEnabled(true);
    polyscope::show(3);
  }
  { // categorical
    polyscope::ScalarRenderImageQuantity* im =
        polyscope::addScalarRenderImageQuantity("render im scalar", dimX, dimY, depthVals, normalVals, scalarVals,
                                                polyscope::ImageOrigin::UpperLeft, polyscope::DataType::CATEGORICAL);
    im->updateBuffers(depthVals, normalVals, scalarVals);
    im->setEnabled(true);
    polyscope::show(3);
  }

  { // RawColorImageQuantity
    polyscope::RawColorRenderImageQuantity* im = polyscope::addRawColorRenderImageQuantity(
        "render im raw color", dimX, dimY, depthVals, colorVals, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, colorVals);
    im->setEnabled(true);
    polyscope::show(3);
  }

  { // RawColorAlphaImageQuantity
    polyscope::RawColorAlphaRenderImageQuantity* im = polyscope::addRawColorAlphaRenderImageQuantity(
        "render im raw color alpha", dimX, dimY, depthVals, colorAlphaVals, polyscope::ImageOrigin::UpperLeft);
    im->updateBuffers(depthVals, colorAlphaVals);
    im->setEnabled(true);
    polyscope::show(3);
    im->setIsPremultiplied(true);
    polyscope::show(3);
  }

  // make sure it doesn't blow up with transparancy
  polyscope::options::transparencyMode = polyscope::TransparencyMode::Simple;
  polyscope::show(3);

  polyscope::options::transparencyMode = polyscope::TransparencyMode::Pretty;
  polyscope::show(3);

  polyscope::options::transparencyMode = polyscope::TransparencyMode::None;

  // make sure removing works
  polyscope::removeFloatingQuantity("render im depth", true);
  polyscope::show(3);

  polyscope::removeAllStructures();
}


// ============================================================
// =============== Implicit tests
// ============================================================

// These also end up testing the image & render image functionality

TEST_F(PolyscopeTest, ImplicitSurfaceRenderImageQuantityTest) {

  // disable for this test
  polyscope::options::warnForInvalidValues = false;

  // sample sdf & color functions
  auto torusSDF = [](glm::vec3 p) {
    float scale = 0.5;
    p /= scale;
    p += glm::vec3{1., 0., 1.};
    glm::vec2 t{1., 0.3};
    glm::vec2 pxz{p.x, p.z};
    glm::vec2 q = glm::vec2(glm::length(pxz) - t.x, p.y);
    return (glm::length(q) - t.y) * scale;
  };
  auto colorFunc = [](glm::vec3 p) {
    glm::vec3 color{0., 0., 0.};
    if (p.x > 0) {
      color += glm::vec3{1.0, 0.0, 0.0};
    }
    if (p.y > 0) {
      color += glm::vec3{0.0, 1.0, 0.0};
    }
    if (p.z > 0) {
      color += glm::vec3{0.0, 0.0, 1.0};
    }
    return color;
  };

  auto scalarFunc = [](glm::vec3 p) { return p.x; };

  polyscope::ImplicitRenderOpts opts;
  polyscope::ImplicitRenderMode mode = polyscope::ImplicitRenderMode::SphereMarch;
  opts.subsampleFactor = 16; // real small, don't want to use much compute

  // plain depth-only implicit surface
  polyscope::DepthRenderImageQuantity* img = polyscope::renderImplicitSurface("torus sdf", torusSDF, mode, opts);
  polyscope::show(3);

  // colored implicit surface
  polyscope::ColorRenderImageQuantity* imgColor =
      polyscope::renderImplicitSurfaceColor("torus sdf color", torusSDF, colorFunc, mode, opts);
  polyscope::show(3);

  // scalar value implicit surface
  polyscope::ScalarRenderImageQuantity* imgScalar =
      polyscope::renderImplicitSurfaceScalar("torus sdf scalar", torusSDF, scalarFunc, mode, opts);
  polyscope::show(3);


  // make sure it doesn't blow up with transparancy
  polyscope::options::transparencyMode = polyscope::TransparencyMode::Simple;
  polyscope::show(3);

  polyscope::options::transparencyMode = polyscope::TransparencyMode::Pretty;
  polyscope::show(3);

  polyscope::options::transparencyMode = polyscope::TransparencyMode::None;

  polyscope::removeAllStructures();
  polyscope::options::warnForInvalidValues = true;
}
