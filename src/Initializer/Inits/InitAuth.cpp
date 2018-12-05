#include "InitAuth.h"

#include "../Initializer.h"

#include "auth/AuthJavascript.h"
#include "auth/Auth.h"
#include "mainwindow.h"

#include "check.h"

namespace initializer {

InitAuth::InitAuth(QThread *mainThread, Initializer &manager)
    : InitInterface(mainThread, manager)
{}

InitAuth::~InitAuth() = default;

void InitAuth::complete() {
    CHECK(authManager != nullptr, "authManager not initialized");
    CHECK(authJavascript != nullptr, "authJavascript not initialized");
}

void InitAuth::sendInitSuccess() {
    sendState(InitState("auth", "init", "auth initialized", TypedException()));
}

InitAuth::Return InitAuth::initialize(std::shared_future<std::reference_wrapper<MainWindow>> mainWindow) {
    authJavascript = std::make_unique<auth::AuthJavascript>(mainThread);
    authManager = std::make_unique<auth::Auth>(*authJavascript);
    authManager->start();
    MainWindow &mw = mainWindow.get();
    emit mw.setAuthJavascript(authJavascript.get());
    emit mw.setAuth(authManager.get());

    sendInitSuccess();
    return std::make_pair(std::ref(*authManager), std::ref(*authJavascript));
}

}