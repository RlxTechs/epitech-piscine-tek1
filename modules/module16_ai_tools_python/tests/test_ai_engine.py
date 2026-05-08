import unittest
from pathlib import Path
from tempfile import TemporaryDirectory
import json

from src.ai_engine import (
    classify_intent,
    generate_reply,
    load_memory,
    add_memory_note,
)


MEMORY = {
    "store_name": "RLX Tech",
    "phone": "06 651 86 69",
    "delivery": "Livraison possible selon la zone.",
    "products": {
        "tv": "TV disponibles.",
        "laptop": "Ordinateurs disponibles.",
        "printer": "Imprimantes disponibles.",
        "stabilizer": "Stabilisateurs disponibles.",
    },
}


class AiEngineTests(unittest.TestCase):
    def test_classify_greeting(self):
        result = classify_intent("Bonsoir")
        self.assertEqual(result.intent, "greeting")

    def test_classify_product_tv(self):
        result = classify_intent("tv 32 dispo ?")
        self.assertEqual(result.intent, "product_tv")

    def test_generate_product_reply(self):
        reply = generate_reply("tv 32 dispo ?", MEMORY)
        self.assertIn("TV disponibles", reply)
        self.assertIn("06 651 86 69", reply)

    def test_generate_delivery_reply(self):
        reply = generate_reply("livraison possible ?", MEMORY)
        self.assertIn("Livraison", reply)

    def test_memory_update(self):
        with TemporaryDirectory() as tmp:
            path = Path(tmp) / "memory.json"
            path.write_text(json.dumps(MEMORY), encoding="utf-8")
            add_memory_note(path, "new_key", "new_value")
            memory = load_memory(path)
            self.assertEqual(memory["new_key"], "new_value")


if __name__ == "__main__":
    unittest.main()
