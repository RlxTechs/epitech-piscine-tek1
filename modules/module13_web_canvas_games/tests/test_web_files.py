import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


class WebCanvasFilesTests(unittest.TestCase):
    def test_files_exist(self):
        self.assertTrue((ROOT / "index.html").exists())
        self.assertTrue((ROOT / "styles.css").exists())
        self.assertTrue((ROOT / "app.js").exists())

    def test_html_contains_canvas(self):
        html = (ROOT / "index.html").read_text(encoding="utf-8")
        self.assertIn("<canvas", html)
        self.assertIn("app.js", html)

    def test_js_contains_game_loop(self):
        js = (ROOT / "app.js").read_text(encoding="utf-8")
        self.assertIn("function loop", js)
        self.assertIn("rectsOverlap", js)
        self.assertIn("requestAnimationFrame", js)


if __name__ == "__main__":
    unittest.main()
