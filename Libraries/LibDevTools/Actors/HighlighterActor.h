/*
 * Copyright (c) 2025, Tim Flynn <trflynn89@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/NonnullRefPtr.h>
#include <LibDevTools/Actor.h>

namespace DevTools {

class HighlighterActor final : public Actor {
public:
    static constexpr auto base_name = "highlighter"sv;

    static NonnullRefPtr<HighlighterActor> create(DevToolsServer&, String name, WeakPtr<InspectorActor>);
    virtual ~HighlighterActor() override;

    JsonValue serialize_highlighter() const;

private:
    HighlighterActor(DevToolsServer&, String name, WeakPtr<InspectorActor>);

    virtual void handle_message(Message const&) override;

    WeakPtr<InspectorActor> m_inspector;
};

}
