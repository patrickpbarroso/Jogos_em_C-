.PHONY: all clean

jogar:
	@echo "Qual jogo você deseja jogar?"
	@echo "1 - Jogo da Forca"
	@echo "2 - Jogo da Advinhacao"
	@read escolha; \
	case $$escolha in \
		1) \
		./JogoDaForca/forca.out; \
		;; \
		2) \
		./JogoDaAdvinhacao/jogo_da_advinhacao.out; \
		;; \
		*) \
		echo "Escolha inválida."; \
		;; \
		esac

atualizar:
	cd JogoDaForca && g++ forca.cpp -o forca.out
	cd JogoDaAdvinhacao && g++ jogo_da_advinhacao.cpp -o jogo_da_advinhacao.out
	@echo "Jogos atualizados com sucesso."
