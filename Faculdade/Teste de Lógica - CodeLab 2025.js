class VerificaBalan {
    constructor() {
        this.pairs = { ')': '(', ']': '[', '}': '{' };
        this.aberturas = new Set(['(', '[', '{']);
    }

    valido(s) {
        const pilha = [];
        for (let c of s) {
            if (this.aberturas.has(c)) {
                pilha.push(c);
            } else if (this.pairs[c]) {
                if (pilha.length === 0) {
                    return -1;
                }
                const ultimo = pilha.pop();
                if (ultimo !== this.pairs[c]) {
                    return -1;
                }
            } else {
                return -1; // caractere inválido
            }
        }

        if (pilha.length === 0) {
            return 0;
        } else {
            return -1;
        }
    }
}
