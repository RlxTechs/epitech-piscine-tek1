import json
from dataclasses import dataclass
from pathlib import Path


@dataclass
class IntentResult:
    intent: str
    score: int


INTENT_KEYWORDS = {
    "greeting": ["bonjour", "bonsoir", "salut", "hello", "bjr", "bsr"],
    "price": ["prix", "combien", "tarif", "cout", "coûte"],
    "stock": ["dispo", "disponible", "stock", "avez", "vous avez"],
    "delivery": ["livraison", "livrer", "zone", "adresse"],
    "tech_support": ["probleme", "erreur", "bug", "marche pas", "connexion"],
    "product_tv": ["tv", "tele", "télé", "32", "43", "55"],
    "product_laptop": ["pc", "ordinateur", "laptop", "core i3", "core i5", "core i7"],
    "product_printer": ["imprimante", "printer", "cartouche", "encre"],
    "product_stabilizer": ["stabilisateur", "stabilizer", "1000va", "2000va", "5000va"],
}


def normalize(text: str) -> str:
    return text.lower().strip()


def score_intent(text: str, keywords: list[str]) -> int:
    text = normalize(text)
    score = 0
    for keyword in keywords:
        if keyword in text:
            score += 1
    return score


def classify_intent(text: str) -> IntentResult:
    best_intent = "unknown"
    best_score = 0

    for intent, keywords in INTENT_KEYWORDS.items():
        score = score_intent(text, keywords)
        if score > best_score:
            best_score = score
            best_intent = intent

    return IntentResult(best_intent, best_score)


def load_memory(path: str | Path) -> dict:
    with open(path, "r", encoding="utf-8-sig") as file:
        return json.load(file)


def detect_product_intent(intent: str) -> str | None:
    if intent == "product_tv":
        return "tv"
    if intent == "product_laptop":
        return "laptop"
    if intent == "product_printer":
        return "printer"
    if intent == "product_stabilizer":
        return "stabilizer"
    return None


def generate_reply(text: str, memory: dict) -> str:
    result = classify_intent(text)
    product_key = detect_product_intent(result.intent)

    if product_key:
        product_reply = memory.get("products", {}).get(product_key)
        if product_reply:
            return f"{product_reply}\n📞 Contact : {memory.get('phone', '')}\n🚚 {memory.get('delivery', '')}"

    if result.intent == "greeting":
        return f"Bonjour 👋 Bienvenue chez {memory.get('store_name', 'nous')}. Que cherchez-vous aujourd'hui ?"

    if result.intent == "price":
        return "Quel produit précis voulez-vous ? Donnez le modèle ou la taille, je vous donne le prix disponible."

    if result.intent == "stock":
        return "Dites-moi le produit exact recherché et je vérifie la disponibilité selon le stock."

    if result.intent == "delivery":
        return memory.get("delivery", "Livraison possible selon votre zone.")

    if result.intent == "tech_support":
        return "Expliquez le problème exact, le modèle de l'appareil et ce qui s'affiche à l'écran."

    return "Je peux vous aider. Dites-moi le produit ou le service que vous cherchez."


def add_memory_note(path: str | Path, key: str, value: str) -> dict:
    memory = load_memory(path)
    memory[key] = value

    with open(path, "w", encoding="utf-8") as file:
        json.dump(memory, file, ensure_ascii=False, indent=2)

    return memory


def demo(memory_path: str | Path) -> list[str]:
    memory = load_memory(memory_path)
    messages = [
        "Bonsoir",
        "tv 32 dispo ?",
        "prix ordinateur core i5",
        "livraison a moungali ?",
        "mon imprimante marche pas",
    ]
    return [generate_reply(message, memory) for message in messages]

